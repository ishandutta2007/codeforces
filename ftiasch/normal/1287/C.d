import std.stdio : writeln;

struct IO {
    string readToken() {
        import std.stdio : stdin;
        import std.array : split;
        import std.range : empty, front, popFront;

        while (tokens.empty) {
            tokens = stdin.readln.split;
        }
        string token = tokens.front;
        tokens.popFront;
        return token;
    }

    int readInt() {
        import std.conv : to;

        return readToken.to!(int);
    }

    string[] tokens;
}

void main() {
    import std.algorithm : min, sort;

    IO io;
    int n = io.readInt;
    int[] p = new int[n + 2];
    int target = n >> 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = io.readInt - 1;
        if (~p[i]) {
            if (p[i] &= 1) {
                target--;
            }
        }
    }
    int result = n;
    for (int mask = 0; mask < 1 << 2; ++mask) {
        p[0] = mask & 1, p[n + 1] = mask >> 1;
        int cost = 0, low = 0, high = 0, j = 0, pc = 0, nc = 0;
        int[] positives = new int[n + 1], negatives = new int[n + 1];
        for (int i = 1; i <= n + 1; ++i) {
            if (~p[i]) {
                int length = i - j - 1;
                if (p[i] != p[j]) {
                    cost++, high += length;
                }
                else if (p[i]) {
                    low += length, high += length, negatives[nc++] = length;
                }
                else {
                    positives[pc++] = length;
                }
                j = i;
            }
        }
        positives.sort!("a > b");
        negatives.sort!("a > b");
        for (int i = 0; i < pc && high < target; ++i) {
            cost += 2, high += positives[i];
        }
        for (int i = 0; i < nc && low > target; ++i) {
            cost += 2, low -= negatives[i];
        }
        result = min(result, cost);
    }
    writeln(result);
}