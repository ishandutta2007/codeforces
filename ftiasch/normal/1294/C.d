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

int[] solve(int n)
{
    for (int a = 2; a * a < n; ++a)
    {
        if (n % a == 0)
        {
            for (int b = a + 1; b * b < n / a; ++b)
            {
                if (n / a % b == 0)
                {
                    return [a, b, n / a / b];
                }
            }
        }
    }
    return null;
}

void main()
{
    int T = readInt;
    while (T--)
    {
        auto res = solve(readInt);
        if (res)
        {
            writeln("YES");
            writeln(res[0], " ", res[1], " ", res[2]);
        }
        else
            writeln("NO");
    }
}