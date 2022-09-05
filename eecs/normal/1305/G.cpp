#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, LIM = 262144;
int n, C, fa[maxn], a[maxn];
long long ans;
pair<int, int> mx[LIM], cand[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline bool test(int x, int y) { return find(x) == find(y); }
inline void unite(int x, int y) { C--, fa[find(x)] = find(y); }

void upd(pair<int, int> &p, int x) {
    if (a[x] > a[p.first]) {
        if (!test(x, p.first)) p.second = p.first;
        p.first = x;
    } else if (a[x] > a[p.second] && !test(p.first, x)) {
        p.second = x;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    iota(fa, fa + n + 1, 0);
    C = n + 1, a[n + 1] = -LIM;
    while (C > 1) {
        fill(mx, mx + LIM, make_pair(n + 1, n + 1));
        fill(cand, cand + n + 1, make_pair(n + 1, n + 1));
        for (int i = 0; i <= n; i++) {
            upd(mx[a[i]], i);
        }
        for (int i = 1; i < LIM; i <<= 1) {
            for (int j = 0; j < LIM; j++) if (!(i & j)) {
                upd(mx[i | j], mx[j].first), upd(mx[i | j], mx[j].second);
            }
        }
        for (int i = 0; i <= n; i++) {
            int j = find(i), S = (LIM - 1) & ~a[i];
            int o = a[cand[j].first] + a[cand[j].second];
            if (!test(i, mx[S].first) && o < a[i] + a[mx[S].first]) {
                cand[j] = {i, mx[S].first};
            } else if (!test(i, mx[S].second) && o < a[i] + a[mx[S].second]) {
                cand[j] = {i, mx[S].second};
            }
        }
        for (int i = 0; i <= n; i++) if (i == find(i)) {
            if (cand[i].second > n || test(i, cand[i].second)) continue;
            unite(i, cand[i].second), ans += a[cand[i].first] + a[cand[i].second];
        }
    }
    printf("%lld\n", ans - accumulate(a, a + n + 1, 0LL));
    return 0;
}