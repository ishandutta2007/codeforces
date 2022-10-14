import std.algorithm;
import std.conv;
import std.format;
import std.range;
import std.stdio;
import std.typecons;
import std.outbuffer;
import std.algorithm.mutation;
import std.container.array;

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
    string s = readToken;
    int[] dp = new int[n];
    int[] maxdp = new int[26];
    for (int i = 0; i < n; ++i)
    {
        int c = s[i] - 'a';
        dp[i] = 1;
        for (int j = c + 1; j < 26; ++j)
        {
            dp[i] = max(dp[i], maxdp[j] + 1);
        }
        maxdp[c] = max(maxdp[c], dp[i]);
    }
    writeln(dp.maxElement);
    auto buf = new OutBuffer();
    for (int i = 0; i < n; ++i)
    {
        buf.write(format("%d", dp[i]));
        if (i + 1 < n)
        {
            buf.write(' ');
        }
    }
    writeln(buf.toString());
}