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
    int a = readInt;
    int b = readInt;
    int c = readInt;
    int n = readInt;
    int sum = a + b + c + n;
    if (sum % 3)
    {
        return false;
    }
    sum /= 3;
    return a <= sum && b <= sum && c <= sum;
}

void main()
{
    int T = readInt;
    while (T--)
    {
        writeln(solve ? "YES" : "NO");
    }
}