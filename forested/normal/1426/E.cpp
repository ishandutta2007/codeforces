// Template
#include "bits/stdc++.h"
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T>
inline bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T> 
inline bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
struct IOSET {
    IOSET() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} ioset;

class PrimalDual {
    struct Edge {
        int to, cap, cost, rev;
    };
    using pii = pair<int, int>;
    int inf = 1001001001;
    
    vector<vector<Edge>> G;
    
public:
    PrimalDual(int n) : G(n) {}
    
    void AddEdge(int from, int to, int cap, int cost) {
        G[from].push_back(Edge{to, cap, cost, (int)G[to].size()});
        G[to].push_back(Edge{from, 0, -cost, (int)G[from].size() - 1});
    }
    
    int MinimumCostFlow(int s, int t, int f) {
        vector<int> h(G.size(), 0);
        int ans = 0;
        
        while (f > 0) {
            vector<int> dist(G.size(), inf), prevv(G.size(), -1), preve(G.size(), -1);
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            dist[s] = 0;
            pq.push(pii(0, s));
            while (!pq.empty()) {
                pii p = pq.top();
                pq.pop();
                if (p.first > dist[p.second]) continue;
                for (int i = 0; i < G[p.second].size(); ++i) {
                    Edge &e = G[p.second][i];
                    if (e.cap == 0 || dist[e.to] <= dist[p.second] + e.cost + h[p.second] - h[e.to]) continue;
                    dist[e.to] = dist[p.second] + e.cost + h[p.second] - h[e.to];
                    prevv[e.to] = p.second;
                    preve[e.to] = i;
                    pq.push(pii(dist[e.to], e.to));
                }
            }
            if (dist[t] == inf) return -1;
            for (int i = 0; i < G.size(); ++i) h[i] += dist[i];
            
            int min_cap = f;
            for (int v = t; v != s; v = prevv[v]) min_cap = min(min_cap, G[prevv[v]][preve[v]].cap);
            f -= min_cap;
            ans += h[t] * min_cap;
            for (int v = t; v != s; v = prevv[v]) {
                G[prevv[v]][preve[v]].cap -= min_cap;
                G[v][G[prevv[v]][preve[v]].rev].cap += min_cap;
            }
        }
        
        return ans;
    }
};

// Main
int main() {
    int n, a1, a2, a3, b1, b2, b3;
    cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    PrimalDual G(8);
    G.AddEdge(0, 1, a1, 0);
    G.AddEdge(0, 2, a2, 0);
    G.AddEdge(0, 3, a3, 0);
    rep(i, 1, 4) rep(j, 4, 7) {
        if (i == 1 && j == 5) {
            G.AddEdge(i, j, inf, 1);
        } else if (i == 2 && j == 6) {
            G.AddEdge(i, j, inf, 1);
        } else if (i == 3 && j == 4) {
            G.AddEdge(i, j, inf, 1);
        } else {
            G.AddEdge(i, j, inf, 0);
        }
    }
    G.AddEdge(4, 7, b1, 0);
    G.AddEdge(5, 7, b2, 0);
    G.AddEdge(6, 7, b3, 0);
    cout << G.MinimumCostFlow(0, 7, n) << "\n";
    cout << min(a1, b2) + min(a2, b3) + min(a3, b1) << "\n";
}