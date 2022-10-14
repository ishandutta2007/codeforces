import std.stdio : stdin, write, writeln;

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
    import core.bitop : bsf, popcnt;
    import std.algorithm : max;

    IO io;
    int n = io.readInt();
    long[] a = new long[n];
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            a[cnt] = io.readLong;
            if (a[cnt]) {
                cnt++;
            }
        }
        n = cnt;
    }
    bool[] ok = new bool[1 << n];
    long[] sum = new long[1 << n];
    for (int msk = 1; msk < 1 << n; ++msk) {
        int sz = popcnt(msk);
        {
            int j = bsf(msk);
            sum[msk] = sum[msk ^ (1 << j)] + a[j];
        }
        if (sum[msk] + sz & 1) {
            long low = sum[msk] - sz + 1, high = sum[msk] + sz - 1;
            for (int subset = msk - 1 & msk; subset && !ok[msk]; subset = subset - 1 & msk) {
                ok[msk] |= low <= 2 * sum[subset] && 2 * sum[subset] <= high;
            }
        }
    }
    int[] dp = new int[1 << n];
    for (int msk = 1; msk < 1 << n; ++msk) {
        if (ok[msk] && !dp[msk]) {
            dp[msk] = 1;
            int comp = (1 << n) - 1 ^ msk;
            for (int subset = comp; subset; subset = subset - 1 & comp) {
                dp[msk | subset] = max(dp[msk | subset], dp[subset] + 1);
            }
        }
    }
    writeln(n - dp[(1 << n) - 1]);
}