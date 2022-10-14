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
    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        int g = io.readInt;
        int b = io.readInt;
        int req = n + 1 >> 1;
        int k = (req - 1) / g;
        writeln(max(cast(long) k * (g + b) + (req - k * g), n));
    }
}