#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <bitset>
#include <cmath>
#include <cassert>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<vector<int> > d, g;
void dfs(int i, int u)
{
    for (int v : g[u]) if (d[i][v] == -1)
    {
        d[i][v] = d[i][u] + 1;
        dfs(i, v);
    }
}
void upd(int& a, int b)
{
    a = max(a, b);
}
const int minf = -1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        g.assign(n, {});
        d.assign(n, vector<int>(n, -1));
        for (int i = 0, u, v; i < n - 1; i++)
        {
            cin >> u >> v;
            g[--u].push_back(--v);
            g[v].push_back(u);
        }
        for (int i = 0; i < n; i++) d[i][i] = 0, dfs(i, i);
        vector<int> ans(n + 1, n + 1), pf(n + 1, minf), sf(n + 1, minf);
        for (int i = 0; i < n; i++)
        {
            for (int x = 0; x <= n; x++) pf[x] = sf[x] = minf;
            for (int j = 0; j < n; j++)
            {
                if (d[i][j] < d[0][j])
                {
                    upd(pf[d[0][j] - d[i][j]], d[0][j]);
                    upd(sf[d[0][j] - d[i][j]], d[i][j]);
                }
                else
                {
                    upd(pf[0], d[0][j]);
                }
            }
            for (int x = 1; x <= n; x++) upd(pf[x], pf[x - 1]);
            for (int x = n; x >= 1; x--) upd(sf[x - 1], sf[x]);
            for (int x = 1; x <= n; x++)
            {
                int val = max(pf[x], sf[x] + x);
                ans[x] = min(ans[x], val);
            }
        }
        for (int x = 1; x <= n; x++) cout << ans[x] << " \n"[x == n];
    }
    return 0;
}