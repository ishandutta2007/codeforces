module E;

import std.stdio : readln, write, writeln;

struct IO {
    import std.conv : to;
    import std.range : empty, front, popFront, split;

    string readToken() {
        while (tokens.empty) {
            tokens = readln.split;
        }
        auto token = tokens.front;
        tokens.popFront;
        return token;
    }

    int readInt() {
        return readToken.to!int;
    }

    string[] tokens;
}

bool solve(int n, int target) {
    import std.algorithm : min;

    int[] count = new int[n];
    int i = 0, sum = 0;
    for (; i < n && (1 << i) - 1 < n; ++i) {
        count[i] = min(1 << i, n - ((1 << i) - 1));
        sum += i * count[i];
    }
    int maxd = i;
    if (sum > target) {
        return false;
    }
    for (; i--;) {
        while (count[i] > 1) {
            count[i]--;
            if (sum + maxd - i < target) {
                sum += maxd - i, count[maxd++]++;
            }
            else {
                count[i + target - sum]++;
                goto end;
            }
        }
    }
    return false;
end:
    int start = 0;
    int[] p = new int[n];
    for (int k = 1; k < n; ++k) {
        for (int j = 0; j < count[k]; ++j) {
            p[start + count[k - 1] + j] = start + (j >> 1);
        }
        start += count[k - 1];
    }
    writeln("YES");
    for (int k = 1; k < n; ++k) {
        write(p[k] + 1, " \n"[k + 1 == n]);
    }
    return true;
}

void main() {
    IO io;
    int T = io.readInt;
    while (T--) {
        int n = io.readInt;
        int target = io.readInt;
        if (!solve(n, target)) {
            writeln("NO");
        }
    }
}