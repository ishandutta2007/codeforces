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
    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        string s = io.readToken;
        int i = 0;
        while (i < n && (s[i] - '0') % 2 == 0) {
            i++;
        }
        if (i == n) {
            writeln(-1);
        }
        else {
            int j = n - 1;
            while (j >= 0 && (s[j] - '0') % 2 == 0) {
                j--;
            }
            if (i == j) {
                writeln(-1);
            }
            else {
                writeln(s[i], s[j]);
            }
        }
    }
}