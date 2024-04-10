#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <array>
typedef long long ll;
using namespace std;

const int maxn = 1e5 + 128, logn = 18, maxqu = 11;
//const int maxn = 128, logn = 18, maxqu = 11;
vector<vector<int> > g(maxn), l(logn, vector<int>(maxn, 0)), my(maxn);
vector<vector<vector<int> > > best(logn, vector<vector<int>>(maxn));
vector<int> d(maxn, 0);
void merge(vector<int>& res, const vector<int>& a, const vector<int>& b)
{
    int ia = 0, ib = 0;
    vector<int> tmp;
    while (tmp.size() < maxqu && (ia < a.size() || ib < b.size()))
    {
        if (ia < a.size() && (ib == b.size() || a[ia] < b[ib])) tmp.push_back(a[ia++]);
        else tmp.push_back(b[ib++]);
    }
    res = tmp;
}
void dfs(int v = 0, int p = -1)
{
    sort(my[v].begin(), my[v].end());
    my[v].resize(min((int)my[v].size(), maxqu));
    for (int i = 1; i < logn; i++)
    {
        l[i][v] = l[i - 1][l[i - 1][v]];
        merge(best[i][v], best[i - 1][v], best[i - 1][l[i - 1][v]]);
    }
    for (int i : g[v])
    {
        if (i == p) continue;
        l[0][i] = v;
        d[i] = d[v] + 1;
        best[0][i] = my[v];
        dfs(i, v);
    }
}
vector<int> best_lca(int u, int v)
{
    if (d[u] < d[v]) swap(u, v);
    int ou = u, ov = v;
    vector<int> ans;
    for (int i = 0; i < logn; i++)
    {
        if ((1 << i) & (d[u] - d[v]))
        {
            merge(ans, best[i][u], ans);
            u = l[i][u];
        }
    }
    if (u == v)
    {
        merge(ans, ans, my[ou]);
        return ans;
    }
    for (int i = logn - 1; i >= 0; i--)
    {
        if (l[i][u] != l[i][v])
        {
            merge(ans, best[i][u], ans);
            merge(ans, best[i][v], ans);
            u = l[i][u], v = l[i][v];
        }
    }
    merge(ans, best[0][u], ans);
    merge(ans, my[ou], ans);
    merge(ans, my[ov], ans);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0, a, b; i < n - 1; i++) cin >> a >> b, g[--a].push_back(--b), g[b].push_back(a);
    for (int i = 0, c; i < m; i++) cin >> c, my[--c].push_back(i + 1);
    dfs();
    for (int i = 0; i < q; i++)
    {
        int v, u, a;
        cin >> v >> u >> a; v--, u--;
        vector<int> ans = best_lca(u, v);
        a = min((int)ans.size(), a);
        //cout << "           ";
        cout << a << " ";
        for (int j = 0; j < a; j++) cout << ans[j] << " ";
        cout << "\n";
    }
    return 0;
}