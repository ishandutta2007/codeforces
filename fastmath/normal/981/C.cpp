#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

vector <int> g[MAXN];
int a[MAXN];

int dfs(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        return dfs(v, u);
    }
    return u;
}

bool comp(int i, int j) {
    return g[i].size() < g[j].size();
}

signed main()
{
    //freopen("1.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; ++i) a[i] = i;
    sort(a, a + n, comp);

    if (2 < g[a[n - 2]].size()) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    int u = a[n - 1];
    cout << g[u].size() << '\n';
    for (int v : g[u]) {
        cout << u + 1 << ' ' << dfs(v, u) + 1 << '\n';
    }

    return 0;
}