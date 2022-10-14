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
        auto s = readToken;
        int[Tuple!(int, int)] tbl;
        tbl[tuple(0, 0)] = 0;
        int x = 0, y = 0;
        auto best = tuple(n + 1, 0, 0);
        for (int i = 0; i < n; ++i)
        {
            final switch (s[i])
            {
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'D':
                y--;
                break;
            case 'U':
                y++;
            }
            int idx = tbl.get(tuple(x, y), -1);
            if (idx != -1)
                best = min(best, tuple(i - idx + 1, idx + 1, i + 1));
            tbl[tuple(x, y)] = i + 1;
        }
        if (best[0] <= n)
        {
            writeln(best[1], " ", best[2]);
        }
        else
        {
            writeln(-1);
        }

    }
}