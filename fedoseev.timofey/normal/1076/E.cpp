#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;

int tin[N], tout[N];
int h[N];
vector <int> g[N];

int timer = 0;

void dfs(int u, int p) {
    if (p == -1) {
        h[u] = 0;
    }
    else {
        h[u] = h[p] + 1;
    }
    tin[u] = timer++;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer++;
}

struct fenwick {
    int n;
    vector <int> f;
    void init(int nn) {
        n = nn;
        f.resize(nn);
    }
    void modify(int ind, int val) {
        for (int i = ind; i < n; i |= i + 1) {
            f[i] += val;
        }
    }
    int get(int ind) {
        int sum = 0;
        for (int i = ind; i >= 0; i &= i + 1, --i) {
            sum += f[i];
        }
        return sum;
    }
};

struct event {
    int u, d, x;
    event(int u, int d = 0, int x = -1) : u(u), d(d), x(x) {}
    bool operator<(const event &other) const {
        if (h[u] + d != h[other.u] + other.d) return h[u] + d > h[other.u] + other.d;
        return x > other.x;
    }
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);
    int m;
    cin >> m;
    vector <event> events;
    for (int i = 0; i < m; ++i) {
        int u, d, x;
        cin >> u >> d >> x;
        --u;
        events.emplace_back(u, d, x);
    }
    for (int i = 0; i < n; ++i) events.emplace_back(i, 0, -1);
    sort(events.begin(), events.end());
    vector <int> ans(n);
    int mx = timer;
    fenwick f;
    f.init(mx + 7);
    for (auto &e : events) {
        if (e.x == -1) {
            ans[e.u] = f.get(tin[e.u]);
        }
        else {
            f.modify(tin[e.u], e.x);
            f.modify(tout[e.u] + 1, -e.x);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}