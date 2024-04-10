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

bool solve()
{
    int n = readInt;
    auto cnt = [0, 0];
    for (int i = 0; i < n; ++i)
        cnt[readInt % 2] = 1;
    if (cnt[1])
    {
        if (cnt[0])
        {
            return true;
        }
        return n % 2 == 1;
    }
    else
    {
        return false;
    }
}

void main()
{
    int T = readInt;
    while (T--)
    {
        writeln(solve ? "YES" : "NO");
    }
}