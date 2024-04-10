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

int solve(string s) {
    int n = cast(int) s.length;
    int i = 0;
    while (i < n && s[i] == '0') {
        i++;
    }
    if (i == n) {
        return 0;
    }
    int j = n - 1;
    while (s[j] == '0') {
        j--;
    }
    int result = 0;
    for (; j > i; j--) {
        result += s[j] == '0';
    }
    return result;
}

void main() {
    IO io;
    int T = io.readInt;
    while (T--) {
        writeln(solve(io.readToken));
    }
}