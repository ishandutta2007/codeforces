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
    import std.algorithm : max, min;

    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        int x = io.readInt;
        int y = io.readInt;
        writeln(min(max(x + y - n + 1, 1), n), " ", min(x + y - 1, n));
    }
}