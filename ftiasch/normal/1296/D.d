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
    int n = readInt;
    int a = readInt;
    int b = readInt;
    int k = readInt;
    int[] need = new int[n];
    for (int i = 0; i < n; ++i)
    {
        int hp = readInt;
        int s = a + b;
        int rounds = (hp + s - 1) / s;
        hp -= (rounds - 1) * s;
        need[i] = (hp + a - 1) / a - 1;
    }
    sort(need);
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        if (need[i] <= k)
        {
            k -= need[i], result++;
        }
    }
    writeln(result);
}