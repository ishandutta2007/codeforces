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
typedef long long ll;
typedef long double ld;
using namespace std;

vector<vector<int> > g;
vector<int> vis;
void dfs(int v = 0)
{
    vis[v] = true;
    for (int i : g[v])
    {
        if (vis[i]) continue;
        dfs(i);
    }
}
void dfs2(int v, vector<int>& ans, vector<int> &good)
{
    vis[v] = true;
    if (good[v] == 0)
    {
        ans.push_back(v);
        good[v] = 2;
        for (int i : g[v]) good[i] = 1;
    }
    for (int i : g[v])
    {
        if (vis[i]) continue;
        dfs2(i, ans, good);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vis.assign(n, 0);
        g.clear();
        g.resize(n);
        vector<int> d(n, 0);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[--a].push_back(--b);
            g[b].push_back(a);
            d[a]++;
            d[b]++;
        }
        dfs(0);
        if (*min_element(vis.begin(), vis.end()) == 0)
        {
            cout << "NO\n";
            continue;
        }
        vector<int> ans;
        vector<int> good(n, 0);
        vis.assign(n, 0);
        dfs2(max_element(d.begin(), d.end()) - d.begin(), ans, good);
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (int i : ans) cout << i + 1 << " ";
        cout << "\n";
    }
    return 0;
}