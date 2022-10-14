import std.algorithm;
import std.conv : to;
import std.numeric : gcd;
import std.range;
import std.stdio;
import std.typecons : Tuple, tuple;

string readToken()
{
    static string[] tokens;
    while (tokens.empty)
        tokens = readln.split;
    auto token = tokens.front;
    tokens.popFront;
    return token;
}

int readInt()
{
    return readToken.to!int;
}

void main()
{
    int n = readInt;
    auto a = new int[n];
    for (int i = 0; i < n; ++i)
        a[i] = readInt;
    int m = a.maxElement;
    auto cnt = new int[m + 1];
    auto mu = new int[m + 1];
    mu[1] = 1;
    for (int d = 1; d <= m; ++d)
    {
        if (!mu[d])
            continue;
        cnt[d]++;
        for (int i = d * 2; i <= m; i += d)
            cnt[i]++, mu[i] -= mu[d];
    }
    auto divs = new int[][m + 1];
    for (int i = 1; i <= m; ++i)
        divs[i] = new int[cnt[i]];
    fill(cnt, 0);
    for (int d = 1; d <= m; ++d)
        if (mu[d])
            for (int i = d; i <= m; i += d)
                divs[i][cnt[i]++] = d;
    fill(cnt, 0);
    for (int i = 0; i < n; ++i)
        cnt[a[i]]++;
    long result = m;
    int[] stack = new int[m], subcnt = new int[m + 1];
    for (int g = 1; g <= m; ++g)
    {
        int m1 = m / g;
        int top = 0;
        for (int x = m1; x >= 1; --x)
            if (cnt[g * x])
            {
                int coprimes = 0;
                foreach (d; divs[x])
                    coprimes += mu[d] * subcnt[d];
                while (coprimes)
                {
                    int y = stack[--top];
                    if (gcd(x, y) == 1)
                        coprimes--, result = max(result, cast(long) g * x * y);
                    foreach (d; divs[y])
                        subcnt[d]--;
                }
                foreach (d; divs[x])
                    subcnt[d]++;
                stack[top++] = x;
            }
        while (top--)
            foreach (d; divs[stack[top]])
                subcnt[d]--;
    }
    writeln(result);
}