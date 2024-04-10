#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <array>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxw = 51;
const ll inf = 1e18;
// 0-th level means that we can pick a new pair of roads
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(n);
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        g[--u].push_back({ --v, w });
        g[v].push_back({ u, w });
    }
    vector<ll> dist(n * maxw, inf);
    set<pair<ll, int> > s{ {0, 0} };
    while (!s.empty())
    {
        ll d = s.begin()->first;
        int vr = s.begin()->second;
        int u = s.begin()->second / maxw, l = s.begin()->second % maxw;
        s.erase(s.begin());
        if (dist[vr] != inf) continue;
        dist[vr] = d;
        for (pair<int, int>& i : g[u])
        {
            int nwlvl = (l ? 0 : i.second);
            int nwvr = i.first * maxw + nwlvl;
            if (dist[nwvr] != inf) continue;
            int val = i.second * i.second + (l ? 2 * i.second * l : 0);
            s.insert({ dist[vr] + (ll)val, nwvr });
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i * maxw] == inf) cout << "-1 ";
        else cout << dist[i * maxw] << " ";
    }
    cout << "\n";
    return 0;
}