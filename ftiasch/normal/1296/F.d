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

const int N = 5000;

int n;
int[N] a, b, c, depth, head, edgeid, value;
int[N << 1] endp, next;

void prepare(int u)
{
    for (int iter = head[u]; ~iter; iter = next[iter])
        if ((iter >> 1) != (edgeid[u] >> 1))
        {
            int v = endp[iter];
            depth[v] = depth[u] + 1;
            edgeid[v] = iter;
            prepare(v);
        }
}

void add_edge(int i, int a, int b)
{
    endp[i] = b, next[i] = head[a], head[a] = i;
}

void main()
{
    int n = readInt;
    for (int i = 0; i < n; ++i)
        head[i] = -1, value[i] = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        int a = readInt - 1;
        int b = readInt - 1;
        add_edge(i << 1, a, b);
        add_edge(i << 1 | 1, b, a);
    }
    depth[0] = edgeid[0] = -1;
    prepare(0);
    int q = readInt;
    for (int i = 0; i < q; ++i)
    {
        a[i] = readInt - 1;
        b[i] = readInt - 1;
        c[i] = readInt;
        int u = a[i], v = b[i];
        while (u != v)
        {
            if (depth[u] > depth[v])
            {
                value[edgeid[u] >> 1] = max(value[edgeid[u] >> 1], c[i]);
                u = endp[edgeid[u] ^ 1];
            }
            else
            {
                value[edgeid[v] >> 1] = max(value[edgeid[v] >> 1], c[i]);
                v = endp[edgeid[v] ^ 1];
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < q; ++i)
    {
        int u = a[i], v = b[i], mi = 1000000;
        while (u != v)
        {
            if (depth[u] > depth[v])
            {
                mi = min(mi, value[edgeid[u] >> 1]);
                u = endp[edgeid[u] ^ 1];
            }
            else
            {
                mi = min(mi, value[edgeid[v] >> 1]);
                v = endp[edgeid[v] ^ 1];
            }
        }
        ok &= mi == c[i];
    }
    if (ok)
        for (int i = 0; i < n - 1; ++i)
            writeln(value[i]);
    else
        writeln(-1);
}