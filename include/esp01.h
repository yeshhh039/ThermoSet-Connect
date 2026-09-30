#ifndef _ESP01_H_
#define _ESP01_H_

/* ---- WiFi network credentials ---- */
#define WIFI_SSID     "ThermoSet_Connect"
#define WIFI_PASSWORD "yash3669"
#define TS_WRITE_API_KEY "OLLU4M6UN8QHST8M"
#define SP_CHANNEL_ID    3497053
#define SP_READ_API_KEY  "B0XV2UDJY10QYYLP"
#define SP_FIELD         1


/* Check AT command communication */
int esp01_connectAP_AT(void);

/* Disable command echo */
int esp01_connectAP_ATE0(void);

/* Configure TCP single connection mode */
int esp01_connectAP_TCP_MODE(void);

/* Disconnect from access point */
int esp01_connectAP_QUIT_AP(void);

/* Connect ESP01 to WiFi access point */
int esp01_connectAP_JOIN_AP(void);

/* Send data to ThingSpeak cloud (main data channel) */
int esp01_sendToThingspeak(int field, int num);

/* Read the latest value of a field from a ThingSpeak channel
   (used to fetch the remotely-entered set point)               */
int esp01_readThingspeakField(unsigned int channel_id, int field, char *read_key);

/* Upload sensor / status data (LCD status + retry wrapper) */
void update_data(int field, int num);

/* Poll the set-point entry channel and sync EEPROM/set_point if changed.
   Returns 1 if the set point was updated, 0 if unchanged, -1 on failure. */
int sync_cloud_setpoint(unsigned int *set_point);

/* Initialize ESP01 module (AT handshake + join WiFi) */
void init_esp01(void);

#endif
