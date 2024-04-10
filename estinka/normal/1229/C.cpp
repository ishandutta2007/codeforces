#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <array>
#include <bitset>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e5 + 128, s = 350;
int ns = 0;
vector<int> lil(maxn, 0), big(maxn, 0), num(maxn, -1), invnum, curnum(maxn);
vector<vector<int> > g(maxn);
vector<bitset<maxn> > nn, added;
vector<vector<int> > process(maxn);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        if (a < b) swap(a, b);
        g[--a].push_back(--b);
        g[b].push_back(a);
        // we have a > b
        lil[a] ++;
        big[b] ++;
    }
    int ns = 5;
    for (int i = 0; i < n; i++) if (g[i].size() > s) ns++;
    added.resize(ns);
    nn.resize(ns);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += lil[i] * 1ll * big[i];
        curnum[i] = i;
        if (g[i].size() > s)
        {
            invnum.push_back(i);
            num[i] = invnum.size() - 1;
            for (int j : g[i]) nn[num[i]][j] = 1;
        }
        for (int j = 0; j < invnum.size(); j++)
        {
            if (i > invnum[j] && nn[j][i] && !added[j][i])
            {
                added[j][i] = 1;
                process[invnum[j]].push_back(i);
            }
        }
    }
    cout << ans << "\n";
    int q;
    cin >> q;
    for (int i = 0, v; i < q; i++)
    {
        cin >> v; v--;
        if (g[v].size() > s)
        {
            for (int j : process[v])
            {
                ans -= big[j] * 1ll * lil[j];
                lil[j]--; big[j]++;
                ans += big[j] * 1ll * lil[j];
                added[num[v]][j] = 0;
            }
            process[v].clear();
        }
        else
        {
            for (int j : g[v])
            {
                if (curnum[j] > curnum[v])
                {
                    ans -= big[j] * 1ll * lil[j];
                    lil[j]--; big[j]++;
                    ans += big[j] * 1ll * lil[j];
                }
            }
        }
        ans -= big[v] * 1ll * lil[v];
        big[v] = 0;
        lil[v] = g[v].size();
        curnum[v] = n + i;
        for (int j = 0; j < invnum.size(); j++)
        {
            if (nn[j][v] && !added[j][v])
            {
                added[j][v] = 1;
                process[invnum[j]].push_back(v);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}