import std.algorithm;
import std.conv;
import std.range;
import std.stdio;
import std.algorithm.mutation;

string[] tokens;

string readToken()
{
    while (tokens.empty)
    {
        tokens = readln.split;
    }
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
    int m = readInt;
    int[][] a = new int[][n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = readInt - 1;
        }
    }

    int[] count = new int[n];

    int result = 0;
    for (int j = 0; j < m; ++j)
    {
        fill(count, 0);
        for (int i = 0; i < n; ++i)
        {
            int x = a[i][j];
            if (x < n * m && x % m == j)
            {
                count[(i + n - (x - j) / m) % n]++;
            }
        }
        int best = n;
        for (int i = 0; i < n; ++i)
        {
            int x = a[i][j];
            if (x < n * m && x % m == j)
            {
                int moves = (i + n - (x - j) / m) % n;
                best = min(best, n - count[moves] + moves);
            }
        }
        result += best;
    }
    writeln(result);
}