#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, q, a[maxn], b[maxn], w[maxn];
__int128 c1[maxn], c2[maxn];

void add(__int128 *c, int p, __int128 v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

__int128 sum(__int128 *c, int p) {
    __int128 s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), b[i] = i - a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        add(c1, i, w[i]), add(c2, i, 1LL * b[i] * w[i]);
    }
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        if (x < 0) {
            x *= -1, add(c1, x, -w[x]), add(c2, x, -1LL * b[x] * w[x]);
            w[x] = y;
            add(c1, x, w[x]), add(c2, x, 1LL * b[x] * w[x]);
        } else {
            auto chk = [&](int st) {
                int l = x, r = y, p = x - 1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (a[mid] <= st + mid - x) l = (p = mid) + 1;
                    else r = mid - 1;
                }
                __int128 s = (st - x) * (sum(c1, p) - sum(c1, x - 1)) + sum(c2, p) - sum(c2, x - 1);
                s -= (st - x) * (sum(c1, y) - sum(c1, p)) + sum(c2, y) - sum(c2, p);
                return s;
            };
            int l0 = 1, r0 = 1000000000, ans;
            while (l0 <= r0) {
                int mid = (l0 + r0) >> 1;
                auto t1 = chk(mid), t2 = chk(mid + 1);
                if (t1 <= t2) ans = t1 % P, r0 = mid - 1;
                else l0 = mid + 1;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}