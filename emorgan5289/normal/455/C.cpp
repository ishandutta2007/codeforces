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

struct unionfind {

    int length;
    vector<int> parent;

    unionfind(int s) : length(s), parent(s) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int rep(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b) {
        a = rep(a);
        b = rep(b);
        if (a != b)
            parent[b] = a;
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }
};

const int maxn = 300005;
unionfind uf(maxn);
vector<int> adj[maxn];
int d[maxn], c[maxn];

void u(int x, int y) {
    if (uf.query(x, y)) return;
    int a = d[uf.rep(x)], b = d[uf.rep(y)];
    uf.unite(x, y);
    d[uf.rep(x)] = max((a+1)/2 + (b+1)/2 + 1, max(a, b));
}

int q(int x) {
    return d[uf.rep(x)];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, l; cin >> n >> m >> l;
    fill(d, d+maxn, 0); fill(c, c+maxn, -2);
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x].pb(y), adj[y].pb(x);
        uf.unite(x, y);
    }
    queue<int> s;
    for (int i = 1; i <= n; i++)
        if (i == uf.rep(i)) {
            s.push(i); int j; c[i] = -1;
            while (!s.empty()) {
                j = s.front(); s.pop();
                for (auto& k : adj[j])
                    if (c[k] == -2) {
                        s.push(k); c[k] = -1;
                    }
            }
            s.push(j); c[j] = 0;
            while (!s.empty()) {
                j = s.front(); s.pop();
                for (auto& k : adj[j])
                    if (c[k] == -1) {
                        s.push(k); c[k] = c[j]+1;
                    }
            }
            d[i] = c[j];
        }
    for (int i = 0; i <= n; i++)
        debug(i, uf.rep(i), d[i]);
    while (l--) {
        int t, x, y; cin >> t;
        if (t == 1) {
            cin >> x; cout << q(x) << "\n";
        } else {
            cin >> x >> y; u(x, y);
        }
    }
}