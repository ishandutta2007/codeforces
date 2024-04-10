module main;

import std.stdio : writeln;

struct IO {
    string readToken() {
        import std.range : empty, front, popFront, split;
        import std.stdio : readln;

        while (tokens.empty) {
            tokens = readln.split;
        }
        auto token = tokens.front;
        tokens.popFront;
        return token;
    }

    int readInt() {
        import std.conv : to;

        return readToken.to!int;
    }

    string[] tokens;
}

void main() {
    import core.bitop : popcnt;
    import std.algorithm : max;

    IO io;
    int T = io.readInt;
    while (T--) {
        int[3] count;
        for (int i = 0; i < 3; ++i) {
            count[i] = io.readInt;
        }
        int result = 0;
        for (int mask = 0; mask < 1 << 8; mask += 2) {
            bool ok = true;
            for (int i = 0; i < 3; ++i) {
                int c = count[i];
                for (int s = 0; s < 8; ++s) {
                    if ((s >> i & 1) && (mask >> s & 1)) {
                        c--;
                    }
                }
                ok &= c >= 0;
            }
            if (ok) {
                result = max(result, popcnt(mask));
            }
        }
        writeln(result);
    }
}