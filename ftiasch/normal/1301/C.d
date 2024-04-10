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

long binom2(int n) {
    return n * (n + 1L) >> 1;
}

void main() {
    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        int m = io.readInt;
        int sz = (n - m) / (m + 1);
        int cnt = (n - m) % (m + 1);
        writeln(binom2(n) - (m + 1 - cnt) * binom2(sz) - cnt * binom2(sz + 1));
    }
}