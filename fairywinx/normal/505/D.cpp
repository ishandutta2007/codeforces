#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const int N = 1e5 + 228;

vector<int> G[N];
int used[N];
int timer = 0;
int who[N];
bool val[N];
int sz[N];

bool dfs(int v) {
    sz[timer]++;
    used[v] = 1;
    who[v] = timer;
    bool find = false;
    for (int i : G[v]) {
        if (used[i] == 1) {
            find = true;
        }
        if (used[i] == 0) {
            if (dfs(i))
                find = true;
        }
    }
    used[v] = 2;
    return find;
}

struct dsu {
    vector<int> p, sz, val;
    dsu(int n) {
        p.resize(n);
        iota(all(p), 0);
        sz.resize(n);
        val.resize(n, 0);
    }

    int get(int a) {
        if (a == p[a])
            return a;
        return p[a] = get(p[a]);
    }

    void merge(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return;

        p[a] = b;
        sz[b] += sz[a], val[b] |= val[a];
    }
};

void dfs2(int v, dsu &d) {
    used[v] = 1;
    for (int i : G[v]) {
        d.merge(who[v], who[i]);
        if (!used[i])
            dfs2(i, d);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (dfs(i))
                val[timer] = 1;
            ++timer;
        }
    }
    dsu d(timer);
    for (int i = 0; i < timer; ++i)
        d.val[i] = val[i], d.sz[i] = sz[i];
    fill(used, used + n, 0);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs2(i, d);
    }
    for (int i = 0; i < timer; ++i) {
        if (i == d.get(i)) {
            if (d.val[i])
                ans += d.sz[i];
            else
                ans += d.sz[i] - 1;
        }
    }
    cout << ans << '\n';
}