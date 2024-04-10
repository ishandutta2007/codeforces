import std.container;
import std.conv;
import std.range;
import std.stdio;
import std.typecons;
import std.algorithm.mutation;
import std.algorithm.searching;

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

const int N = 200000;

int n;
Array!int[N] tree;

int[] bfs(int s)
{
    int[] dist = new int[n];
    fill(dist, -1);
    dist[s] = 0;
    int[] queue = new int[n];
    int rear = 0;
    queue[rear++] = s;
    for (int head = 0; head < rear; ++head)
    {
        int u = queue[head];
        foreach (v; tree[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }
    return dist;
}

int argmax(int[] dist)
{
    return cast(int) dist.enumerate.maxElement!"a.value"[0];
}

auto solve()
{
    int x = argmax(bfs(0));
    int[] dx = bfs(x);
    int y = argmax(dx);
    int diameter = dx[y];
    int[] dy = bfs(y);
    if (diameter == n - 1)
    {
        int z = 0;
        while (z == x || z == y)
        {
            z++;
        }
        return tuple(n - 1, x, y, z);
    }
    int z = n.iota.maxElement!((z) => dx[z] + dy[z]);
    return tuple(dx[z] + dy[z] + diameter >> 1, x, y, z);
}

void main()
{
    n = readInt;
    for (int i = 0; i < n - 1; ++i)
    {
        int a = readInt - 1;
        int b = readInt - 1;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    auto res = solve();
    writeln(res[0]);
    writeln(res[1] + 1, " ", res[2] + 1, " ", res[3] + 1);
}