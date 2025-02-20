#pragma once

#include <AudioServer/AudioServerEndpoint.h>
#include <LibCore/CoreIPCClient.h>

class ABuffer;

class AClientConnection : public IPC::Client::ConnectionNG<AudioServerEndpoint> {
    C_OBJECT(AClientConnection)
public:
    AClientConnection();

    virtual void handshake() override;
    void enqueue(const ABuffer&);

    int get_main_mix_volume();
    void set_main_mix_volume(int);
};
