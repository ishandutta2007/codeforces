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
    import std.algorithm : swap;

    IO io;
    int n = io.readInt;
    int[] a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = io.readInt;
    }
    int m = 0;
    for (int k = 30; k >= 0; --k) {
        int found = -1;
        for (int i = m; i < n; ++i) {
            if (a[i] >> k & 1) {
                if (found == -1) {
                    found = i;
                }
                else {
                    found = n;
                }
            }
        }
        if (m <= found && found < n) {
            swap(a[m++], a[found]);
        }
    }
    for (int i = 0; i < n; ++i) {
        writeln(a[i]);
    }
}