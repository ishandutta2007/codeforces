#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 3e5 + 7;
int n, m, k;
vector <ii> g[N];

int to[N], cost[N];

/*
struct Mem {
    int u, d;
    bool bad;
    bool operator < (Const Mem m) const {
        return (d < m.d) || (d == m.d && bad < m.bad) || (d == m.d && bad == m.bad && u < m.u);
    }   
};
*/  

const int INF = 1e18 + 7;
int dist[N];
bool bad[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].app(mp(v, c)); g[v].app(mp(u, c));
    }   
    set <ii> ms;

    for (int i = 0; i < N; ++i)
        dist[i] = INF;

    for (int i = 0; i < k; ++i) {
        cin >> to[i] >> cost[i];
        //g[1].app(mp(to[i], cost[i]));
        //g[to[i]].app(mp(1, cost[i]));
        dist[to[i]] = min(dist[to[i]], cost[i]);
        bad[to[i]] = 1;
    }   
    for (int i = 1; i <= n; ++i)
        if (dist[i] != INF)
            ms.insert(mp(dist[i], i));

    dist[1] = 0;
    ms.insert(mp(0, 1));
    int cnt_bad = 0;
    while (ms.size()) {
        int u = ms.begin()->s;

        //cout << "ms " << u << ' ' << dist[u] << ' ' << bad[u] << endl;

        ms.erase(ms.begin());
        cnt_bad += bad[u];
        for (auto e : g[u]) {
            int v = e.f, c = e.s;
            if (dist[u] + c < dist[v] || (dist[u] + c == dist[v] && bad[v])) {
                ms.erase(mp(dist[v], v));
                dist[v] = dist[u] + c;
                ms.insert(mp(dist[v], v));
                bad[v] = 0;

                //cout << "upd " << v << " : " << u << endl;
                
            }   
        }   
    }   

    cout << k - cnt_bad << endl;
}