#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[100100], b[100100];

struct edge {
    int set, ver, cost;
    bool operator<(const edge& rhs) const {
        return cost > rhs.cost;
    }
};

int dsu[200200];
int get(int v) {
    if (dsu[v] < 0)
        return v;
    return dsu[v] = get(dsu[v]);
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (-dsu[a] < -dsu[b])
            swap(a, b);
        dsu[a] += dsu[b];
        dsu[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    fill_n(dsu, m + n, -1);
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<edge> edges;
    for (int i = 0; i < m; ++i) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; ++j) {
            int ver;
            cin >> ver;
            --ver;
            edges.push_back({i, ver, a[i] + b[ver]});
        }
    }
    sort(all(edges));
    ll ans = 0;
    for (const auto& ed : edges) {
        if (get(ed.set) != get(m + ed.ver)) {
            unite(ed.set, m + ed.ver);
        } else {
            ans += ed.cost;
        }
    }
    cout << ans << endl;
}