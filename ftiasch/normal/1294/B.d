import std.algorithm;
import std.conv;
import std.range;
import std.stdio;
import std.outbuffer;
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
        auto a = new Tuple!(int, int)[n + 1];
        for (int i = 1; i <= n; ++i)
            a[i][0] = readInt, a[i][1] = readInt;
        sort(a);
        bool ok = true;
        for (int i = 1; i <= n; ++i)
            ok &= a[i - 1][1] <= a[i][1];
        if (ok)
        {
            writeln("YES");
            OutBuffer buf = new OutBuffer();
            for (int i = 1; i <= n; ++i)
            {
                for (int y = a[i - 1][0]; y < a[i][0]; ++y)
                    buf.write('R');
                for (int y = a[i - 1][1]; y < a[i][1]; ++y)
                    buf.write('U');
            }
            writeln(buf);
        }
        else
        {
            writeln("NO");
        }
    }
}