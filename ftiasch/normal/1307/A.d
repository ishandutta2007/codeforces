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
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int a = io.readInt;
            while (m >= i && a) {
                result++, m -= i, a--;
            }
        }
        writeln(result);
    }
}