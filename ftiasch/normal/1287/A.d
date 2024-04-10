import std.algorithm;
import std.conv : to;
import std.container;
import std.numeric : gcd;
import std.range;
import std.stdio;
import std.typecons : Tuple, tuple;

string readToken() {
    static string[] tokens;
    while (tokens.empty)
        tokens = readln.split;
    auto token = tokens.front;
    tokens.popFront;
    return token;
}

int readInt() {
    return readToken.to!int;
}

void main() {
    int T = readInt;
    while (T--) {
        int n = readInt;
        string s = readToken;
        int result = 0, count = 0;
        for (int i = n; i--;) {
            if (s[i] == 'P') {
                count++;
            }
            else {
                result = max(result, count), count = 0;
            }
        }
        writeln(result);
    }
}