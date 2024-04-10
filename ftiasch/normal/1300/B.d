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

    string[] tokens;
}

void main() {
    import std.math : abs;
    import std.algorithm : min, sort;

    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        int[] a = new int[n << 1];
        for (int i = 0; i < n << 1; ++i) {
            a[i] = io.readInt;
        }
        sort(a);
        int result = a[(n << 1) - 1] - a[0], half = n - 1;
        for (int i = 0; i < n << 1; ++i) {
            result = min(result, abs(a[i] - a[half + (half >= i)]));
        }
        writeln(result);
    }
}