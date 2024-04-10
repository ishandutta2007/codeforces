#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

int getInt()
{
    int n; cin >> n; return n;
}

vector<int> getVectorInt(int size)
{
    vector <int> v(size);
    for (int i = 0; i < size; i++) v[i] = getInt();
    return v;
}

vector< vector<int> > getGraph(vector<int> edges, int size)
{
    vector< vector<int> > graph(size);
    for (int i = 0; i < (edges.size() / 2); i++)
    {
        int a = edges[i * 2] - 1, b = edges[i * 2 + 1] - 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}

int n = getInt(), m = getInt();
vector <int> sDown(n), dDown(n), sUp(n), dUp(n);
int up[200000][20];
vector <int> tin(n), tout(n);
int timer = 0;

vector < vector<int> > g = getGraph(getVectorInt(2 * n - 2), n);

void launchDFS(int v = 0, int p = 0)
{
    tin[v] = timer++;

    up[v][0] = p;
    for (int i = 1; i < 20; i++) up[v][i] = up[up[v][i - 1]][i - 1];

    sDown[v] = 0, dDown[v] = 0;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (to == p) continue;
        launchDFS(to, v);
        sDown[v] += sDown[to];
        dDown[v] += dDown[to];
    }
    dDown[v] += sDown[v];
    sDown[v]++;
    sUp[v] = n - sDown[v];

    tout[v] = timer++;
}

void launchSecondDFS(int v = 0, int p = 0)
{
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (to == p) continue;
        dUp[to] = dUp[v] + dDown[v] + sUp[v] - dDown[to] - sDown[to];
        launchSecondDFS(to, v);
    }
}

bool upper(int a, int b)
{
    return (tin[a] <= tin[b]) && (tout[a] >= tout[b]);
}

int findLCA(int a, int b)
{
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    for (int i = 19; i >= 0; i--)
        if (!upper(up[a][i], b)) a = up[a][i];
    return up[a][0];
}

int findHeight(int a, int p)
{
    if (a == p) return 0;
    int h = 0;
    for (int i = 19; i >= 0; i--)
        if (!upper(up[a][i], p)) a = up[a][i], h += (1 << i);
    return h + 1;
}

int findHigher(int a, int h)
{
    for (int i = 19; i >= 0; i--)
        if ((h >> i) & 1) a = up[a][i];
    return a;
}

void doQuery()
{
    int a = getInt(), b = getInt();
    a--, b--;
    if (upper(a, b)) swap(a, b);
    if (upper(b, a))
    {
        int h = findHeight(a, b) + 1;
        int c = findHigher(a, h - 2);
        long long mulSizes = sDown[a] * sUp[c];
        long long totalSum = sDown[a] * dUp[c] + sUp[c] * dDown[a];
        long double one = 1.0, ans = one * totalSum / mulSizes + h;
        cout.precision(10);
        cout << ans << "\n";
    }
    else
    {
        int p = findLCA(a, b);
        int h = findHeight(a, p) + findHeight(b, p);
        long long mulSizes = sDown[a] * sDown[b];
        long long totalSum = sDown[a] * dDown[b] + sDown[b] * dDown[a];
        long double one = 1.0, ans = one * totalSum / mulSizes + h + 1;
        cout.precision(10);
        cout << ans << "\n";
    }
}

void doQueries()
{
    for (int i = 0; i < m; i++) doQuery();
}

main()
{
    launchDFS();
    launchSecondDFS();
    doQueries();
}