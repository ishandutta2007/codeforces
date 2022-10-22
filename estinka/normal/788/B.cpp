#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e6 + 79;
vector<vector<int> > g(maxn);
vector<int> vis(maxn, 0), d(maxn, 0), d2(maxn, 0);
void dfs(int v)
{
    vis[v] = true;
    for (int i : g[v])
    {
        if (!vis[i]) dfs(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int loops = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[--x].push_back(--y);
        g[y].push_back(x); d2[x]++; d2[y]++;
        if (x == y)
        {
            loops++;
        }
        else
        {
            d[x]++; d[y]++;
        }
    }
    for (int i = 0; i < n; i++) if (d2[i] == 0) vis[i] = 1;
    for (int i = 0; i < n; i++)
    {
        if (d2[i] != 0)
        {
            dfs(i);
            break;
        }
    }
    if (*min_element(vis.begin(), vis.begin() + n) == 0)
    {
        cout << "0\n";
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (d[i] * 1ll * (d[i] - 1)) / 2ll;
    }
    ans += (m - loops) * 1ll * loops;
    ans += (loops * 1ll * (loops - 1)) / 2ll;
    cout << ans << "\n";
    return 0;
}