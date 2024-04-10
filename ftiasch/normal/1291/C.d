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

void main() {
    import std.algorithm : max, min;

    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        int m = io.readInt - 1;
        int k = min(m, io.readInt);
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = io.readInt();
        }
        int result = 0;
        for (int ctr = 0; ctr <= k; ++ctr) {
            int worst = cast(int) 1e9;
            for (int arb = 0; arb <= m - k; ++arb) {
                worst = min(worst, max(a[ctr + arb], a[n - 1 - (m - (ctr + arb))]));
            }
            result = max(result, worst);
        }
        writeln(result);
    }
}