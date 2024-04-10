import std.algorithm : maxElement, sort, swap;
import std.conv : to;
import std.range;
import std.stdio;
import std.typecons : Tuple, tuple;
import std.algorithm.mutation;

// import std.container.array;

string readToken()
{
    static string[] tokens;
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
        auto a = new Tuple!(int, int)[n];
        for (int i = 0; i < n; ++i)
        {
            a[i][0] = readInt;
            a[i][1] = readInt;
        }
        sort(a);
        int result = 0, mx0 = -1, mx1 = -1;
        int[] delta = new int[n];
        for (int i = 0; i < n; ++i)
        {
            if (mx0 == -1 || a[mx0][1] < a[i][0])
                result++, delta[i] = -1;
            else
            {
                delta[i] = 0;
                if (mx1 == -1 || a[mx1][1] < a[i][0])
                    delta[mx0]++;
            }
            int x = i;
            if (mx0 == -1 || a[x][1] > a[mx0][1])
                swap(mx0, x);
            if (~x && (mx1 == -1 || a[x][1] > a[mx1][1]))
                mx1 = x;
        }
        writeln(result + delta.maxElement);
    }
}