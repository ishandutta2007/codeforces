#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define int long long

const int INF = 2e18 + 7;
const int MAXN = 2e5 + 7;

vector <pair <int, int>> g[MAXN];
int a[MAXN];
int dist[MAXN];
set <pair <int, int>> ms;

signed main(){
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        c *= 2;
        g[u - 1].push_back({v - 1, c});
        g[v - 1].push_back({u - 1, c});
    }

    for (int i = 0; i < n; ++i){
        cin >> a[i];
        g[n].push_back({i, a[i]});
    }

    for (int i = 0; i < MAXN; ++i) dist[i] = INF;
    dist[n] = 0;
    ms.insert({0, n});
    while (ms.size() != 0){
        int u = ms.begin()->second;
        ms.erase(ms.begin());
        for (pair <int, int> e: g[u]){
            int v = e.first;
            int c = e.second;
            if (dist[u] + c < dist[v]){
                ms.erase({dist[v], v});
                dist[v] = dist[u] + c;
                ms.insert({dist[v], v});
            }
        }
    }
    
    for (int i = 0; i < n; ++i){
        cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}