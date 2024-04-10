import std.algorithm;
import std.conv;
import std.range;
import std.stdio;
import std.typecons;
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
    int q = readInt;
    int x = readInt;
    int[] cnt = new int[x];
    int ans = 0;
    while (q--)
    {
        cnt[readInt % x]++;
        while (cnt[ans % x])
        {
            cnt[ans++ % x]--;
        }
        writeln(ans);
    }
}