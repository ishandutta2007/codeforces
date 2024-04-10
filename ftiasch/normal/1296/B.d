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
    int T = readInt;
    while (T--)
    {
        int n = readInt;
        int res = 0;
        while (n >= 10)
        {
            res += n - n % 10;
            n = n % 10 + n / 10;
        }
        writeln(res + n);
    }
}