#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 30010;
int n, q, w[maxn], h[maxn], p[maxn], p1[maxn], p2[maxn], ip1[maxn], ip2[maxn];
ll f[maxn], w2[maxn], w3[maxn], w4[maxn];

void chk(ll &x, ll y) {
    if (x < y) x = y;
}

bool ok(int x, int y) {
    return p[x] != y;
}

ll cost(int x, int y) {
    return 1LL * w[x] * h[y];
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    iota(p1 + 1, p1 + n + 1, 1);
    sort(p1 + 1, p1 + n + 1, [&](int x, int y) { return w[x] > w[y]; });
    iota(p2 + 1, p2 + n + 1, 1);
    sort(p2 + 1, p2 + n + 1, [&](int x, int y) { return h[x] > h[y]; });
    for (int i = 1; i <= n; i++) {
        ip1[p1[i]] = i, ip2[p2[i]] = i;
    }
    sort(w + 1, w + n + 1, greater<int>());
    sort(h + 1, h + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        p[ip1[i]] = ip2[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            w2[i] = cost(i - 1, i) + cost(i, i - 1);
        }
        if (i > 2) {
            w3[i] = cost(i - 2, i - 1) + cost(i - 1, i) + cost(i, i - 2);
        }
        if (i > 2) {
            w4[i] = cost(i - 2, i) + cost(i - 1, i - 2) + cost(i, i - 1);
        }
    }
    auto solve = [&]() {
        fill(f + 1, f + n + 1, -1e18);
        for (int i = 1; i <= n; i++) {
            if (ok(i, i)) {
                chk(f[i], f[i - 1] + cost(i, i));
            }
            if (i > 1 && ok(i - 1, i) && ok(i, i - 1)) {
                chk(f[i], f[i - 2] + w2[i]);
            }
            if (i > 2 && ok(i - 2, i - 1) && ok(i - 1, i) && ok(i, i - 2)) {
                chk(f[i], f[i - 3] + w3[i]);
            }
            if (i > 2 && ok(i - 2, i) && ok(i - 1, i - 2) && ok(i, i - 1)) {
                chk(f[i], f[i - 3] + w4[i]);
            }
        }
        return f[n];
    };
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        swap(p[ip1[a]], p[ip1[b]]);
        printf("%lld\n", solve());
    }
    return 0;
}