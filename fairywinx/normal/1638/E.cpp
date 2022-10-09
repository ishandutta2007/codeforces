#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

struct SegTree {
    vector<int> t;
    vector<int> mod;
    int n;

    void push(int v) {
        if (mod[v] != -2) {
            t[v * 2 + 1] = mod[v];
            t[v * 2] = mod[v];
            mod[v * 2 + 1] = mod[v];
            mod[v * 2] = mod[v];
            mod[v] = -2;
        }
    }

    int get(int v, int l, int r, int pos) {
        if (r - l == 1)
            return t[v];
        int m = (l + r) / 2;
        push(v);
        if (pos < m)
            return get(v * 2 + 1, l, m, pos);
        else
            return get(v * 2, m, r, pos);
    }

    int get(int pos) {
        return get(1, 0, n, pos);
    }

    void update(int v, int l, int r, int L, int R, int val) {
        if (R <= l || r <= L)
            return;
        if (L <= l && r <= R) {
            t[v] = val;
            mod[v] = val;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(v * 2 + 1, l, m, L, R, val);
        update(v * 2, m, r, L, R, val);
    }

    void update(int l, int r, int val) {
        update(1, 0, n, l, r, val);
    }

    SegTree(int _n) {
        n = _n;
        int sz = 1;
        while (sz < 2 * n)
            sz *= 2;
        t.resize(sz);
        mod.resize(sz, -2);
    }
};

struct SegTree2 {
    vector<pair<int, int>> t;
    vector<pair<int, int>> mod;

    const pair<int, int> bad = {-1, -1};
    int n;

    void push(int v) {
        if (mod[v] != bad) {
            t[v * 2 + 1] = mod[v];
            t[v * 2] = mod[v];
            mod[v * 2 + 1] = mod[v];
            mod[v * 2] = mod[v];
            mod[v] = bad;
        }
    }

    pair<int, int> get(int v, int l, int r, int pos) {
        if (r - l == 1)
            return t[v];
        int m = (l + r) / 2;
        push(v);
        if (pos < m)
            return get(v * 2 + 1, l, m, pos);
        else
            return get(v * 2, m, r, pos);
    }

    pair<int, int> get(int pos) {
        return get(1, 0, n, pos);
    }

    void update(int v, int l, int r, int L, int R, pair<int, int> val) {
        if (R <= l || r <= L)
            return;
        if (L <= l && r <= R) {
            t[v] = val;
            mod[v] = val;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(v * 2 + 1, l, m, L, R, val);
        update(v * 2, m, r, L, R, val);
    }

    void update(int l, int r) {
        if (r - l != 0)
            update(1, 0, n, l, r, {l, r});
    }

    SegTree2(int _n) {
        n = _n;
        int sz = 1;
        while (sz < 2 * n)
            sz *= 2;
        t.resize(sz);
        mod.resize(sz, bad);
    }
};

struct SegTreeSum {
    vector<long long> t;
    vector<long long> mod;
    int n;

    long long get(int v, int l, int r, int pos) {
        if (r - l == 1)
            return t[v];
        int m = (l + r) / 2;
        if (pos < m)
            return get(v * 2 + 1, l, m, pos) + mod[v];
        else
            return get(v * 2, m, r, pos) + mod[v];
    }

    long long get(int pos) {
        return get(1, 0, n, pos);
    }

    void update(int v, int l, int r, int L, int R, long long val) {
        if (R <= l || r <= L)
            return;
        if (L <= l && r <= R) {
            t[v] += val;
            mod[v] += val;
            return;
        }
        int m = (l + r) / 2;
        update(v * 2 + 1, l, m, L, R, val);
        update(v * 2, m, r, L, R, val);
    }

    void update(int l, int r, long long val) {
        update(1, 0, n, l, r, val);
    }

    SegTreeSum(int _n) {
        n = _n;
        int sz = 1;
        while (sz < 2 * n)
            sz *= 2;
        t.resize(sz);
        mod.resize(sz);
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

    int n, q;
    cin >> n >> q;

    SegTree c(n);
    SegTree2 seg(n);
    seg.update(0, n);
    c.update(0, n, 0);
    SegTreeSum ans(n);
    vector<array<int, 4>> Q;

    for (int t = 0; t < q; ++t) {
        string type;
        cin >> type;
        if (type == "Add") {
            int c, x;
            cin >> c >> x;
            Q.push_back({0, c - 1, x, -1});
        } else if (type == "Color") {
            int l, r, x;
            cin >> l >> r >> x;
            Q.push_back({1, l - 1, r, x - 1});
        } else {
            int pos;
            cin >> pos;
            Q.push_back({2, pos - 1, -1, -1});
        }
    }
    vector<long long> f(n);

    
    for (int t = 0; t < q; ++t) {
        if (Q[t][0] == 0) {
            f[Q[t][1]] += Q[t][2];
        } else if (Q[t][0] == 1) {
            int pos = Q[t][1];
            int R = Q[t][2];
            int Color = Q[t][3];
            while (pos < R) {
                if (c.get(pos) != Color) {
                    int nw = c.get(pos);
                    auto z = seg.get(pos);
                    int left = pos, right = min(R, z.second);
                    seg.update(z.first, left);
                    seg.update(right, z.second);
                    int col1 = -1, col2 = -1;
                    if (left != 0)
                        col1 = c.get(left - 1);
                    if (right != n)
                        col2 = c.get(right);
        
                    if (col1 == Color && col2 == Color) {
                        seg.update(seg.get(left - 1).first, seg.get(right).second);
                    } else if (col1 == Color) {
                        seg.update(seg.get(left - 1).first,  right);
                    } else if (col2 == Color) {
                        seg.update(left, seg.get(right).second);
                    } else {
                        seg.update(left, right);
                    }
                    ans.update(left, right, f[nw] - f[Color]);
                    c.update(left, right, Color);
                }
                pos = seg.get(pos).second;
            }
        } else {
            int pos = Q[t][1];
            int Color = c.get(pos);
            cout << ans.get(pos) + f[Color] << '\n';
        }
    }
}