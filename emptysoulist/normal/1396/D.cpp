#include <bits/stdc++.h>
constexpr int P = 1000000007, N = 2e3;
std::vector<int> vx, vy;
int sum[4 * N], tag[4 * N], mx[4 * N], mn[4 * N];
void pull(int p) {
    sum[p] = (sum[2 * p] + sum[2 * p + 1]) % P;
    mx[p] = std::max(mx[2 * p], mx[2 * p + 1]);
    mn[p] = std::min(mn[2 * p], mn[2 * p + 1]);
}
void modify(int p, int l, int r, int v) {
    tag[p] = mx[p] = mn[p] = v;
    sum[p] = 1ll * (vx.back() - vx[v]) * (vx[r] - vx[l]) % P;
}
void push(int p, int l, int r) {
    if (tag[p] == -1)
        return;
    int m = (l + r) / 2;
    modify(2 * p, l, m, tag[p]);
    modify(2 * p + 1, m, r, tag[p]);
    tag[p] = -1;
}
void build(int p, int l, int r, const std::vector<int> &a) {
    tag[p] = -1;
    if (r - l == 1) {
        mx[p] = mn[p] = a[l];
        sum[p] = 1ll * (vx.back() - vx[a[l]]) * (vx[r] - vx[l]) % P;
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m, a);
    build(2 * p + 1, m, r, a);
    pull(p);
}
void rangeModify(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x || mn[p] >= v)
        return;
    if (l >= x && r <= y && mx[p] <= v)
        return modify(p, l, r, v);
    push(p, l, r);
    int m = (l + r) / 2;
    rangeModify(2 * p, l, m, x, y, v);
    rangeModify(2 * p + 1, m, r, x, y, v);
    pull(p);
}
int main() {
///	freopen("test.in", "r", stdin ) ;
//	freopen("std.out", "w", stdout ) ;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k, L;
    std::cin >> n >> k >> L;
    std::vector<int> x(n), y(n), c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i] >> c[i];
        --c[i];
    }
    std::vector<int> px(n);
    std::iota(px.begin(), px.end(), 0);
    std::sort(px.begin(), px.end(), [&](int i, int j) {
        return x[i] < x[j];
    });
    std::vector<int> py(n);
    std::iota(py.begin(), py.end(), 0);
    std::sort(py.begin(), py.end(), [&](int i, int j) {
        return y[i] < y[j];
    });
    vx = x;
    vy = y;
    vx.push_back(-1);
    vx.push_back(L);
    vy.push_back(-1);
    vy.push_back(L);
    std::sort(vx.begin(), vx.end());
    std::sort(vy.begin(), vy.end());
    for (int i = 0; i < n; ++i)
        x[px[i]] = y[py[i]] = i + 1;
    int ans = 0;
    for (int u = k; u <= n; ++u) {
        std::vector<int> r(n, n + 1), cnt(k);
        std::vector<std::set<int>> s(k);
        int cur = 0;
        for (int l = 0, i = 0; l < n; ++l) {
            while (i < n && cur < k) {
                int j = px[i];
                if (y[j] <= u && !cnt[c[j]]++)
                    ++cur;
                ++i;
            }
            if (cur == k)
                r[l] = i;
            int j = px[l];
            if (y[j] <= u && !--cnt[c[j]])
                --cur;
        }
        build(1, 0, n, r);
        for (int i = 0; i < n; ++i)
            if (y[i] <= u)
                s[c[i]].insert(x[i]);
        int res = 0;
        for (int d = 0; d + 1 <= u; ++d) {
            res = (res + 1ll * (vy[d + 1] - vy[d]) * sum[1]) % P;
            int j = py[d];
            auto it = s[c[j]].erase(s[c[j]].find(x[j]));
            int r = it == s[c[j]].end() ? n + 1 : *it;
            int l = it == s[c[j]].begin() ? 0 : *std::prev(it);
            rangeModify(1, 0, n, l, x[j], r);
        }
        ans = (ans + 1ll * res * (vy[u + 1] - vy[u])) % P;
    }
    std::cout << ans << "\n";
    return 0;
}