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
        int[] a = new int[n];
        int result = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = io.readInt;
            if (!a[i]) {
                a[i]++, result++;
            }
            sum += a[i];
        }
        if (!sum) {
            result++;
        }
        writeln(result);
    }
}