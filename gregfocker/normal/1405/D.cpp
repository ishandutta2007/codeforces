#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = (int) 1e5 + 7;
int n;
int a;
int b;
int da;
int db;
int diam;
vector<int> g[N];
int dist[N];
int down[N];

void dfs(int x, int p)
{
    down[x] = 0;
    for (auto &y : g[x])
    {
        if (y != p)
        {
            dist[y] = 1 + dist[x];
            dfs(y, x);
            diam = max(diam, down[x] + 1 + down[y]);
            down[x] = max(down[x], 1 + down[y]);
        }
    }
}

void build(int root, int d[])
{
    diam = 0;
    d[root] = 0;
    dfs(root, -1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen ("input", "r", stdin);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        build(a, dist);
        da = min(da, diam);
        db = min(db, diam);
        if (dist[b] <= da)
        {
            cout << "Alice\n";
            continue;
        }
        if (db > 2 * da)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
        }
    }

}