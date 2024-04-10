#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back
 
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif
 
struct tour {

    vector<vector<pair<int, int>>> adj;
    vector<int> in, bad, circ;
    bool vis[(1<<20)+5];

    // n vertices
    tour(int n) : adj(n), in(n, 0) {}

    void clear(int n) {
        adj.assign(n, {}); in.assign(n, 0);
        bad.clear(); circ.clear();
        fill(vis, vis+(1<<20)+5, 0);
    }

    // edge from i to j
    void edge(int i, int j, int k) {
        adj[j].emplace_back(i, k); in[i]++;
        adj[i].emplace_back(j, k^1); in[j]++;
    }

    void dfs(int i, int p) {
        // Hierholzers algorithm
        while (!adj[i].empty()) {
            auto [j, r] = adj[i].back(); adj[i].pop_back();
            if (vis[r]) continue;
            vis[r^1] = 1;
            dfs(j, r);
        }
        if (p != -1)
            circ.push_back(p);
    }

    // runs in O(E). one time use. assumes graph is connected.
    vector<int> solve() {
        for (int i = 0; i < adj.size(); i++)
            if (in[i]%2 == 1)
                bad.push_back(i);
        if (bad.size() == 0) { // found a circuit
            for (int i = 0; i < adj.size(); i++)
                if (!adj[i].empty()) {
                    dfs(i, -1); return circ;
                }
        }
        return {};
    }
};

const int maxn = 500005;
tour t(0);
int n, a[maxn], b[maxn];
vector<int> res;

bool valid(int k) {
    int mask = (1<<k)-1;
    t.clear(1<<k);
    for (int i = 0; i < n; i++)
        t.edge(a[i]&mask, b[i]&mask, 2*i);
    res = t.solve();
    return res.size() == n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int l = 0, r = 20;
    while (l < r) {
        int m = (l+r+1)/2;
        if (valid(m))
            l = m;
        else
            r = m-1;
    }
    valid(l);
    cout << l << "\n";
    for (auto& x : res)
        cout << x+1 << " " << (x^1)+1 << " ";
}