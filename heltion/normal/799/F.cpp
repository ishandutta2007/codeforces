#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct Seg{
    int n;
    vector<LL> min, added, bitk, bitb;
    Seg(int n) : n(n) {
        min.resize(n << 2);
        added.resize(n << 2);
        bitk.resize(n + 1);
        bitb.resize(n + 1);
    }
    #define ls (v << 1)
    #define rs (ls | 1)
    #define tm ((tl + tr) >> 1)
    void add(int v, int x) {
        added[v] += x;
        min[v] += x;
    }
    void push_down(int v) {
        add(ls, added[v]);
        add(rs, added[v]);
        added[v] = 0;
    }
    void add(int L, int R, int x) {
        function<void(int, int, int)> dfs = [&](int v, int tl, int tr) {
            if (tl >= L and tr <= R) return add(v, x);
            push_down(v);
            if (L <= tm) dfs(ls, tl, tm);
            if (R > tm) dfs(rs, tm + 1, tr);
            min[v] = std::min(min[ls], min[rs]);
        };
        dfs(1, 1, n);
    }
    void add(int y) {
        for (int x = y; x <= n; x += x & -x) bitb[x] += y;
        for (int x = y; x <= n; x += x & -x) bitk[x] += -1;
    }
    void relase() {
        function<int(int, int, int)> dfs = [&](int v, int tl, int tr) {
            if (tl == tr) return tm;
            push_down(v);
            if (min[ls] == 0) return dfs(ls, tl, tm);
            return dfs(rs, tm + 1, tr);
        };
        while (min[1] == 0) {
            int p = dfs(1, 1, n);
            add(p);
            add(p, p, INT_MAX);
        }
    }
    LL sum(vector<LL>& bit, int x) {
        LL res = 0;
        for (; x; x -= x & -x) res += bit[x];
        return res;
    }
    LL sum(int L, int R, int x) {
        if (L > R) return 0;
        return (sum(bitk, R) - sum(bitk, L - 1)) * (x - 1) + sum(bitb, R) - sum(bitb, L - 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> R(m + 1);
    vector<Seg> seg(2, m);
    vector<int> f(m + 1);
    for (int i = 1; i <= m; i += 1) seg[(i & 1) ^ 1].add(i, i, INT_MAX);
    for (int i = 1; i <= n; i += 1) {
        int l, r;
        cin >> l >> r;
        R[l].push_back(r);
        seg[(l & 1) ^ 1].add(l, r, 1);
        if (((r - l) & 1) and r < m) {
            seg[0].add(r + 1, m, 1);
            seg[1].add(r + 1, m, 1);
        }
    }
    LL ans = 0;
    vector<set<int>> s(2);
    for (int i = 1; i <= m; i += 1) {
        for (int r : R[i]) {
            seg[(i & 1) ^ 1].add(i, r, -1);
            if (((r - i) & 1) and r < m) {
                seg[0].add(r + 1, m, -1);
                seg[1].add(r + 1, m, -1);
            }
            s[r & 1].insert(r);
        }
        int x = i;
        for (int j = 0; j < 2; j += 1) {
            while (not s[j].empty() and *s[j].begin() < i) s[j].erase(s[j].begin());
            if (not s[j].empty()) {
                x = max(x, *s[j].rbegin());
                f[i] = 1;
            }
        }
        for (int j = 0; j < 2; j += 1) seg[j].relase();
        int mr = m;
        if (not s[(i & 1) ^ 1].empty()) mr = *s[(i & 1) ^ 1].begin();
        ans += seg[(i & 1)].sum(i, mr, i);
        ans += seg[(i & 1) ^ 1].sum(x + 1, mr, i);
    }
    for (int i = 1, r = 1; i <= m; i += 1) if (not f[i]) {
        r = max(r, i);
        while (r <= m and not f[r]) r += 1;
        ans -= (LL)(r - i + 1) * (r - i) / 2;
    }
    cout << ans << "\n";
    return 0;
}