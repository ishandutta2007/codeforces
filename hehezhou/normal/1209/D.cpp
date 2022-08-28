#include <bits/stdc++.h>
using namespace std;
vector<int> son[110000];
int n, m;
int vis[110000];
void dfs(int x)
{
    vis[x] = 1;
    for (auto i : son[x])
    {
        if (!vis[i])
            dfs(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        son[v].push_back(u);
        son[u].push_back(v);
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            ans--, dfs(i);
    cout << m - ans;
}