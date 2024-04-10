#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 300000;
pair<int, int> tag[maxn << 3], maxx[maxn << 3];
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
void update(int v, pair<int, int> x) {
    tag[v] = max(tag[v], x);
    maxx[v] = max(maxx[v], x);
}
void push_down(int v) {
    if (tag[v].first) {
        update(ls, tag[v]);
        update(rs, tag[v]);
        tag[v] = {0, 0};
    }
}
void update(int v, int tl, int tr, int L, int R, pair<int, int> x) {
    if (tl >= L and tr <= R) return update(v, x);
    push_down(v);
    if (L <= tm) update(ls, tl, tm, L, R, x);
    if (R > tm) update(rs, tm + 1, tr, L, R, x);
    maxx[v] = max(maxx[ls], maxx[rs]);
}
pair<int, int> query(int v, int tl, int tr, int L, int R) {
    if (tl >= L and tr <= R) return maxx[v];
    push_down(v);
    pair<int, int> res = {0, 0};
    if (L <= tm) res = max(res, query(ls, tl, tm, L, R));
    if (R > tm) res = max(res, query(rs, tm + 1, tr, L, R));
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n + 1);
    vector<int> x;
    for (int i = 0, p, l, r; i < m; i += 1) {
        cin >> p >> l >> r;
        v[p].push_back({l, r});
        x.push_back(l);
        x.push_back(r + 1);
    }
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    int k = (int)x.size() - 1;
    pair<int, int> ans = {0, 0};
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i += 1) {
        pair<int, int> y = {0, 0};
        for (auto& [L, R] : v[i]) {
            L = lower_bound(x.begin(), x.end(), L) - x.begin() + 1;
            R = lower_bound(x.begin(), x.end(), R + 1) - x.begin();
            y = max(y, query(1, 1, k, L, R));
        }
        y.first += 1;
        f[i] = y.second;
        y.second = i;
        ans = max(ans, y);
        for (auto [L, R] : v[i]) update(1, 1, k, L, R, y);
    }
    cout << n - ans.first << "\n";
    vector<int> w(n + 1);
    for (int i = ans.second; i; i = f[i]) w[i] = 1;
    for (int i = 1; i <= n; i += 1) if (not w[i]) cout << i << " ";
    return 0;
}