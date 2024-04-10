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
    import std.algorithm : max;

    IO io;
    string s = io.readToken;
    long[] cnt1 = new long[26];
    long[][] cnt2 = new long[][](26, 26);
    for (int i = 0; i < s.length; ++i) {
        int c = s[i] - 'a';
        for (int d = 0; d < 26; ++d) {
            cnt2[d][c] += cnt1[d];
        }
        cnt1[c]++;
    }
    long result = 0;
    for (int c = 0; c < 26; ++c) {
        result = max(result, cnt1[c]);
        for (int d = 0; d < 26; ++d) {
            result = max(result, cnt2[c][d]);
        }
    }
    writeln(result);
}