#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

struct edge {
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    edge() : u(0), v(0), w(0) {}
};

struct fenwick {
    int n;
    vector <int> t;
    fenwick(int nn) {
        t.resize(nn);
        n = nn;
    }
    fenwick() {}

    void clear() {
        for (int i = 0; i < n; ++i) t[i] = 0;
    }
    void modify(int x, int val) {
        for (int i = x; i < n; i |= i + 1) {
            t[i] = max(t[i], val);
        }
    }
    int get(int r) {
        int res = 0;
        for (int i = r; i >= 0; i &= i + 1, --i) {
            res = max(res, t[i]);
        }
        return res;
    }
};

const int N = 1e5 + 7;

fenwick g[N];

vector <int> x[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        --edges[i].u;
        --edges[i].v;
    }
    for (auto e : edges) {
        x[e.u].push_back(e.w);
    }
    for (int i = 0; i < n; ++i) {
        sort(x[i].begin(), x[i].end());
        x[i].resize(unique(x[i].begin(), x[i].end()) - x[i].begin());
        g[i] = fenwick(x[i].size());
    }
    reverse(edges.begin(), edges.end());
    for (int i = 0; i < m; ++i) {
        auto cur = edges[i];
        int ind = lower_bound(x[cur.v].begin(), x[cur.v].end(), cur.w) - x[cur.v].begin();
        ind = (int)x[cur.v].size() - ind - 1;
        int ci = lower_bound(x[cur.u].begin(), x[cur.u].end(), cur.w) - x[cur.u].begin();
        ci = (int)x[cur.u].size() - ci - 1;
        g[cur.u].modify(ci, g[cur.v].get(ind) + 1);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, g[i].get(x[i].size() - 1));
    }
    cout << ans << "\n";
}