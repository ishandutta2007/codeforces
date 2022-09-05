#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, SZ = 250;
int n, q, _a[maxn], _b[maxn], a[maxn], b[maxn], c[maxn];
int bel[maxn], bl[maxn], br[maxn], tag[maxn], cur1[maxn], cur2[maxn];
int tim, fa[maxn], tid[maxn], sz[maxn];
vector<int> G[maxn], ord1[maxn], hull1[maxn], ord2[maxn], hull2[maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]), G[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &_a[i]), _a[i] += _a[fa[i]];
        br[bel[i] = (i - 1) / SZ + 1] = i;
        if (!bl[bel[i]]) bl[bel[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &_b[i]), _b[i] += _b[fa[i]];
    }
    function<void(int)> dfs = [&](int u) {
        tid[u] = ++tim, sz[u] = 1;
        a[tim] = _a[u], b[tim] = _b[u], c[tim] = -_b[u];
        for (int v : G[u]) dfs(v), sz[u] += sz[v];
    };
    dfs(1);
    auto build = [&](int *x, vector<int> &A, vector<int> &B) {
        static long long y[maxn];
        for (int i : A) y[i] = 1LL * x[i] * a[i];
        auto cross = [&](int i, int j, int k) {
            return (__int128)(y[j] - y[i]) * (x[k] - x[j]) <= (__int128)(y[k] - y[j]) * (x[j] - x[i]);
        };
        B.clear();
        for (int i : A) {
            if (!B.empty() && x[B.back()] == x[i]) {
                if (y[i] >= y[B.back()]) B.pop_back();
                else continue;
            }
            while (B.size() > 1 && cross(B[B.size() - 2], B.back(), i)) B.pop_back();
            B.push_back(i);
        }
    };
    auto upd = [&](int k) {
        build(b, ord1[k], hull1[k]), cur1[k] = 0;
        build(c, ord2[k], hull2[k]), cur2[k] = 0;
    };
    for (int k = 1; k <= bel[n]; k++) {
        ord1[k].resize(br[k] - bl[k] + 1);
        iota(ord1[k].begin(), ord1[k].end(), bl[k]);
        sort(ord1[k].begin(), ord1[k].end(), [&](int i, int j) { return b[i] < b[j]; });
        ord2[k].assign(ord1[k].rbegin(), ord1[k].rend()), upd(k);
    }
    while (q--) {
        int op, x, y;
        scanf("%d %d", &op, &x);
        int l = tid[x], r = tid[x] + sz[x] - 1;
        if (op == 1) {
            scanf("%d", &y);
            if (bel[l] == bel[r]) {
                for (int i = l; i <= r; i++) a[i] += y;
            } else {
                for (int i = l; i <= br[bel[l]]; i++) a[i] += y;
                for (int i = bel[l] + 1; i < bel[r]; i++) tag[i] += y;
                for (int i = bl[bel[r]]; i <= r; i++) a[i] += y;
                upd(bel[r]);
            }
            upd(bel[l]);
        } else {
            auto calc = [&](int i) { return abs(1LL * b[i] * (a[i] + tag[bel[i]])); };
            long long ans = 0;
            if (bel[l] == bel[r]) {
                for (int i = l; i <= r; i++) ans = max(ans, calc(i));
            } else {
                for (int i = l; i <= br[bel[l]]; i++) ans = max(ans, calc(i));
                for (int i = bel[l] + 1; i < bel[r]; i++) {
                    auto eval1 = [&](int j) { return 1LL * b[j] * tag[i] + 1LL * b[j] * a[j]; };
                    auto &vec1 = hull1[i];
                    while (cur1[i] + 1 < vec1.size() && eval1(vec1[cur1[i]]) < eval1(vec1[cur1[i] + 1])) cur1[i]++;
                    ans = max(ans, eval1(vec1[cur1[i]]));
                    auto eval2 = [&](int j) { return 1LL * c[j] * tag[i] + 1LL * c[j] * a[j]; };
                    auto &vec2 = hull2[i];
                    while (cur2[i] + 1 < vec2.size() && eval2(vec2[cur2[i]]) < eval2(vec2[cur2[i] + 1])) cur2[i]++;
                    ans = max(ans, eval2(vec2[cur2[i]]));
                }
                for (int i = bl[bel[r]]; i <= r; i++) ans = max(ans, calc(i));
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}