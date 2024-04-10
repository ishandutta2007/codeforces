#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

struct SegTree {
    vector<int> t;
    vector<int> mod;
    int n;
 
    void build(int v, int l, int r, vector<int> &a) {
        if (r - l == 1) {
            t[v] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m, a);
        build(v * 2, m, r, a);
        t[v] = min(t[v * 2 + 1], t[v * 2]);
    }
 
    void push(int v) {
        t[v * 2 + 1] += mod[v];
        t[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
        mod[v * 2] += mod[v];
        mod[v] = 0;
    }
 
    void update(int v, int l, int r, int L, int R, int val) {
        if (R <= l || r <= L)
            return;
        if (L <= l && r <= R) {
            mod[v] += val;
            t[v] += val;
            return;
        }
 
        push(v);
        int m = (l + r) / 2;
        update(v * 2 + 1, l, m, L, R, val);
        update(v * 2, m, r, L, R, val);
        t[v] = min(t[v * 2 + 1], t[v * 2]);
    }
 
    void update(int l, int r, int val) {
        update(1, 0, n, l, r, val);
    }
 
    int get(int v, int l, int r, int L, int R) {
        if (R <= l || r <= L)
            return 1e9 + 228;
        if (L <= l && r <= R)
            return t[v];
    
        push(v);
        int m = (l + r) / 2;
        return min(get(v * 2 + 1, l, m, L, R), get(v * 2, m, r, L, R));
    }
 
    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }
 
    SegTree(int _n, vector<int> a) {
        n = _n;
        int sz = 1;
        while (sz < 2 * n)
            sz *= 2;
        t.resize(sz);
        mod.resize(sz);
        build(1, 0, n, a);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(rall(a));
    a.resize(m);
    sort(all(a));
    n = m;
    vector<vector<int>> b(m);
    vector<pair<int, long long>> ind;
    vector<long long> sr;
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        b[i].resize(c);
        long long sum = 0;
        for (int j = 0; j < c; ++j) {
            cin >> b[i][j];
            sum += b[i][j];
        }
        sr.emplace_back((sum + c - 1) / c);
    }
    sort(all(sr));
    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        val[i] = upper_bound(all(sr), a[i]) - sr.begin() - i - 1;
    }
    SegTree t(n, val);
    string ans;
    for (int i = 0; i < m; ++i) {
        long long sum = 0;
        for (int j = 0; j < (int) b[i].size(); ++j) {
            sum += b[i][j];
        }
        int k = b[i].size();
        long long sr1 = (sum + k - 1) / k;
        for (int j = 0; j < (int) b[i].size(); ++j) {
            long long _sum = sum - b[i][j];
            long long sr2 = (_sum + k - 2) / (k - 1);
            t.update(0, lower_bound(all(a), sr1) - a.begin(), 1);
            t.update(0, lower_bound(all(a), sr2) - a.begin(), -1);
            // cout << sr1 << ' ' << sr2 << '\n';
            if (t.get(0, n) < 0) {
                ans += "0";
            } else {
                ans += "1";
            }
            t.update(0, lower_bound(all(a), sr1) - a.begin(), -1);
            t.update(0, lower_bound(all(a), sr2) - a.begin(), 1);
        }
    }
    // cout << '\n';
    cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}