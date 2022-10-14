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
    import std.algorithm : max, maxElement;

    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        int x = io.readInt;
        int[] a = new int[n];
        bool found = false;
        for (int i = 0; i < n; ++i) {
            a[i] = io.readInt;
            found |= a[i] == x;
        }
        if (found) {
            writeln(1);
        }
        else {
            int maxa = a.maxElement;
            writeln(max(2, (x + maxa - 1) / maxa));
        }
    }
}