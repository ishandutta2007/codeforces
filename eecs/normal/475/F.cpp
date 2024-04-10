#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, ans;
array<int, 2> a[maxn], b[maxn];
vector<int> X[maxn << 2], Y[maxn << 2];
unordered_map<int, vector<int>> Sx, Sy;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r, vector<int> *a, array<int, 2> *b) {
    if (l == r) { a[k] = {b[l][1]}; return; }
    build(ls, l, mid, a, b), build(rs, mid + 1, r, a, b);
    a[k].resize(a[ls].size() + a[rs].size());
    merge(a[ls].begin(), a[ls].end(), a[rs].begin(), a[rs].end(), a[k].begin());
}

int find1(vector<int> *a, int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) {
        auto it = lower_bound(a[k].begin(), a[k].end(), v);
        return it != a[k].end() ? *it : INT_MAX;
    }
    int s = INT_MAX;
    if (mid >= ql) s = find1(a, ls, l, mid, ql, qr, v);
    if (mid < qr) s = min(s, find1(a, rs, mid + 1, r, ql, qr, v));
    return s;
}

int find2(vector<int> *a, int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) {
        auto it = upper_bound(a[k].begin(), a[k].end(), v);
        return it != a[k].begin() ? *prev(it) : INT_MIN;
    }
    int s = INT_MIN;
    if (mid >= ql) s = find2(a, ls, l, mid, ql, qr, v);
    if (mid < qr) s = max(s, find2(a, rs, mid + 1, r, ql, qr, v));
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        b[i] = {a[i][1], a[i][0]};
        Sx[a[i][0]].push_back(a[i][1]);
        Sy[a[i][1]].push_back(a[i][0]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    build(1, 1, n, X, a), build(1, 1, n, Y, b);
    for (auto &p : Sx) {
        sort(p.second.begin(), p.second.end());
    }
    for (auto &p : Sy) {
        sort(p.second.begin(), p.second.end());
    }
    function<void(int, int, int, int)> solve = [&](int u, int d, int l, int r) {
        int _u = lower_bound(a + 1, a + n + 1, array<int, 2>{u, INT_MIN}) - a;
        int _d = lower_bound(a + 1, a + n + 1, array<int, 2>{d + 1, INT_MIN}) - a - 1;
        int _l = lower_bound(b + 1, b + n + 1, array<int, 2>{l, INT_MIN}) - b;
        int _r = lower_bound(b + 1, b + n + 1, array<int, 2>{r + 1, INT_MIN}) - b - 1;
        u = find1(Y, 1, 1, n, _l, _r, u), d = find2(Y, 1, 1, n, _l, _r, d);
        l = find1(X, 1, 1, n, _u, _d, l), r = find2(X, 1, 1, n, _u, _d, r);
        _u = u + 1, _d = d - 1, _l = l + 1, _r = r - 1;
        while (_u < d || _d > u || _l < r || _r > l) {
            if (_u < d) {
                auto it = lower_bound(Sx[_u].begin(), Sx[_u].end(), l);
                if (it == Sx[_u].end() || *it > r) {
                    solve(u, _u - 1, l, r), solve(_u + 1, d, l, r); return;
                }
                _u++;
            }
            if (_d > u) {
                auto it = lower_bound(Sx[_d].begin(), Sx[_d].end(), l);
                if (it == Sx[_d].end() || *it > r) {
                    solve(u, _d - 1, l, r), solve(_d + 1, d, l, r); return;
                }
                _d--;
            }
            if (_l < r) {
                auto it = lower_bound(Sy[_l].begin(), Sy[_l].end(), u);
                if (it == Sy[_l].end() || *it > d) {
                    solve(u, d, l, _l - 1), solve(u, d, _l + 1, r); return;
                }
                _l++;
            }
            if (_r > l) {
                auto it = lower_bound(Sy[_r].begin(), Sy[_r].end(), u);
                if (it == Sy[_r].end() || *it > d) {
                    solve(u, d, l, _r - 1), solve(u, d, _r + 1, r); return;
                }
                _r--;
            }
        }
        ans++;
    };
    solve(-1e9, 1e9, -1e9, 1e9);
    printf("%d\n", ans);
    return 0;
}