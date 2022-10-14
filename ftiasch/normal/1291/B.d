import std.algorithm : max, maxElement;
import std.container : Array;
import std.stdio : stdin, write, writeln;
import std.typecons : Tuple, tuple;

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

    long readLong() {
        import std.conv : to;

        return readToken.to!long;
    }

    string[] tokens;
}

bool solve(int n, int[] a) {
    bool ok = true;
    bool[] prefixOK = new bool[n];

    for (int i = 0; i < n; ++i) {
        ok &= a[i] >= i;
        prefixOK[i] = ok;
    }
    ok = true;
    for (int i = n; i--;) {
        ok &= a[i] >= n - 1 - i;
        if (prefixOK[i] && ok) {
            return true;
        }
    }
    return false;
}

void main() {
    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = io.readInt();
        }
        writeln(solve(n, a) ? "Yes" : "No");
    }
}