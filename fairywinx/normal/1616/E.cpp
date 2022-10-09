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
    }

    void push(int v) {
        t[v * 2 + 1] += mod[v];
        t[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
        mod[v * 2] += mod[v];
        mod[v] = 0;
    }

    void update(int v, int l, int r, int L, int R) {
        if (R <= l || r <= L)
            return;
        if (L <= l && r <= R) {
            mod[v] += 1;
            t[v] += 1;
            return;
        }

        push(v);
        int m = (l + r) / 2;
        update(v * 2 + 1, l, m, L, R);
        update(v * 2, m, r, L, R);
    }

    void update(int l, int r) {
        update(1, 0, n, l, r);
    }

    int get(int v, int l, int r, int pos) {
        if (r - l == 1) {
            return t[v];
        }
        
        push(v);
        int m = (l + r) / 2;
        if (pos < m)
            return get(v * 2 + 1, l, m, pos);
        else
            return get(v * 2, m, r, pos);
    }

    int get(int pos) {
        return get(1, 0, n, pos);
    }

    SegTree(int _n) {
        n = _n;
        vector<int> a(n);
        iota(all(a), 0);
        int sz = 1;
        while (sz < 2 * n)
            sz *= 2;
        t.resize(sz);
        mod.resize(sz);
        build(1, 0, n, a);
    }
};

const long long inf = 1e18 + 228;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    const int C = 30;
    vector<vector<int>> pos(C);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    vector<int> cnt(C);
    long long ans = inf;
    SegTree tr(n);
    long long now = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = t[i] - 'a';
        for (int j = 0; j < tmp; ++j) {
            if (cnt[j] != (int) pos[j].size()) {
                // cout << (char) (j + 'a') << '\n';
                int val = tr.get(pos[j][cnt[j]]);
                ans = min(ans, now + val - i);
            }
        }
        if (cnt[tmp] != (int) pos[tmp].size()) {
            // cout << pos[tmp][cnt[tmp]] << ':';
            int val = tr.get(pos[tmp][cnt[tmp]]);
            // cout << "! " << val << ' ' << i << '\n';
            now += val - i;
            // cout << 0 << ',' << pos[tmp][cnt[tmp]] << '\n';
            if (pos[tmp][cnt[tmp]] != 0)
                tr.update(0, pos[tmp][cnt[tmp]]);
            ++cnt[tmp];
        } else {
            break;
        }
    }
    if (ans != inf)
        cout << ans << '\n';
    else
        cout << -1 << '\n';
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