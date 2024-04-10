#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<vector<int> > g, my;
vector<int> vis, siz;
void dfs(int vr, int col)
{
    my[col].push_back(vr);
    vis[vr] = col;
    for (int i : g[vr])
    {
        if (vis[i] == -1) dfs(i, col);
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
        int n;
        string s;
        cin >> n >> s;
        g.assign(2 * (n + 1), vector<int>()); vis.assign(2 * (n + 1), -1); siz.assign(2 * (n + 1), 0); my.assign(2 * (n + 1), vector<int>());
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                g[i + 1].push_back(n + 1 + i);
                g[n + 1 + i].push_back(i + 1);
            }
            else
            {
                g[i].push_back(n + 2 + i);
                g[n + 2 + i].push_back(i);
            }
        }
        int c = 0;
        vector<int> f(n + 1, 0);
        for (int i = 0; i < g.size(); i++)
        {
            if (vis[i] == -1)
            {
                dfs(i, c);
                for (int j : my[c])
                {
                    if (!f[j % (n + 1)]) siz[c]++;
                    f[j % (n + 1)] = 1;
                }
                for (int j : my[c]) f[j % (n + 1)] = 0;
                c++;
            }
        }
        for (int i = 0; i < n + 1; i++) cout << siz[vis[i]] << " ";
        cout << "\n";
    }
    return 0;
}