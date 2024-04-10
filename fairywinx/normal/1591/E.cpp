#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

struct SegTree {
    vector<int> t;
    int n;
    SegTree() {}
    SegTree(int _n) {
        n = _n;
        int sz = 1;
        while (sz < 4 * n)
            sz = sz * 2;
        t.resize(sz);
    }

    void update(int v, int l, int r, int pos, int val) {
        if (r - l == 1) {
            t[v] += val;
            if (l == 0)
                t[v] = 0;
            return;
        }
        int m = (l + r) / 2;
        if (pos < m)
            update(v * 2 + 1, l, m, pos, val);
        else
            update(v * 2, m, r, pos, val);
        t[v] = t[v * 2 + 1] + t[v * 2];
    }

    void update(int pos, int val) {
        update(1, 0, n, pos, val);
    }

    int get(int v, int l, int r, int L, int &cnt) {
        if (r <= L)
            return -1;
        if (l >= L && t[v] < cnt) {
            cnt -= t[v];
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = get(v * 2 + 1, l, m, L, cnt);
        if (res == -1) {
            res = get(v * 2, m, r, L, cnt);
        }
        return res;
    }

    int get(int L, int cnt) {
        int tmp = cnt;
        return get(1, 0, n, L, tmp);
    }
};

vector<vector<int>> G;
vector<int> cnt;
vector<set<int>> who;
vector<int> a;
vector<int> ans;

SegTree t;

vector<vector<array<int, 3>>> q;

void dfs(int v, int p = -1) {
    who[cnt[a[v]]].erase(a[v]);
    t.update(cnt[a[v]], -1);
    ++cnt[a[v]];
    who[cnt[a[v]]].insert(a[v]);
    t.update(cnt[a[v]], 1);

    for (auto i : q[v]) {
        int z = t.get(i[0], i[1]);
        if (z == -1)
            ans[i[2]] = z;
        else
            ans[i[2]] = *who[z].begin();
    }
    for (int i : G[v]) {
        if (i != p)
            dfs(i, v);
    }
    who[cnt[a[v]]].erase(a[v]);
    t.update(cnt[a[v]], -1);
    --cnt[a[v]];
    who[cnt[a[v]]].insert(a[v]);
    t.update(cnt[a[v]], 1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    a.clear();
    a.resize(n + 10);
    cnt.clear();
    cnt.resize(n + 10);
    who.clear();
    who.resize(n + 10);
    G.clear();
    G.resize(n + 10);
    q.clear();
    q.resize(n + 10);
    ans.clear();
    ans.resize(m);
    t = SegTree(n + 10);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        G[p - 1].push_back(i);
        G[i].push_back(p - 1);
    }
    for (int i = 0; i < m; ++i) {
        int v, l, k;
        cin >> v >> l >> k;
        q[v - 1].push_back({l, k, i});
    }
    dfs(0);
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}