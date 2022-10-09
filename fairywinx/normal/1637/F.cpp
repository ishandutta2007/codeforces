#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 2e5 + 228;

vector<int> G[N];
vector<int> a;
int timer = 0;
vector<int> tin;
vector<int> tout;

const long long inf = 1e18 + 228;

void dfs(int v, int p) {
    tin[v] = timer++;
    for (int i : G[v]) {
        if (i != p)
            dfs(i, v);
    }
    tout[v] = timer;
}

struct SegTree {
    vector<pair<int, int>> t;
    int n;

    void build(int v, int l, int r) {
        if (r - l == 1) {
            t[v] = {0, l};
            return;
        }
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2, m, r);
        t[v] = max(t[v * 2 + 1], t[v * 2]);
    }

    void update(int v, int l, int r, int pos, int val) {
        if (r - l == 1) {
            t[v] = {val, l};
            return;
        }

        int m = (l + r) / 2;
        if (pos < m)
            update(v * 2 + 1, l, m, pos, val);
        else
            update(v * 2, m, r, pos, val);
        t[v] = max(t[v * 2 + 1], t[v * 2]);
    }

    void update(int pos, int val) {
        update(1, 0, n, pos, val);
    }

    pair<int, int> get(int v, int l, int r, int L, int R) {
        if (R <= l || r <= L)
            return {0, 0};
        if (L <= l && r <= R)
            return t[v];
        int m = (l + r) / 2;
        return max(get(v * 2 + 1, l, m, L, R), get(v * 2, m, r, L, R));
    }

    pair<int, int> get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    SegTree(int _n) {
        n = _n;
        t.resize(4 * n);
        build(1, 0, n);
    }
};

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int v = max_element(all(a)) - a.begin();
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    tin.resize(n);
    tout.resize(n);
    dfs(v, -1);
    vector<array<int, 3>> q;
    for (int i = 0; i < n; ++i) {
        if (i != v)
            q.push_back({tin[i], tout[i], a[i]});
    }
    sort(all(q), [] (const array<int, 3> &a, const array<int, 3> &b) {
        return a[1] - a[0] < b[1] - b[0];
    });
    SegTree t(n);
    long long ans = 0;
    for (auto i : q) {
        auto z = t.get(i[0], i[1]);
        ans += max(0, i[2] - z.first);
        t.update(z.second, max(z.first, i[2]));
    }
    vector<int> ch;
    for (int i : G[v]) {
        ch.push_back(t.get(tin[i], tout[i]).first);
    }
    sort(rall(ch));
    if (ch.size() == 1) {
        cout << ans + 2 * a[v] - ch[0] << '\n';
    } else {
        cout << ans + 2 * a[v] - ch[0] - ch[1] << '\n';
    }
}