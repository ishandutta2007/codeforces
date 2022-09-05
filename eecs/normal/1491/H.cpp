#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, B = 300;
int n, q, a[maxn], bel[maxn], bl[maxn], br[maxn], cnt[maxn], tag[maxn], top[maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &a[i]);
        br[bel[i] = (i - 2) / B + 1] = i;
        if (!bl[bel[i]]) bl[bel[i]] = i;
    }
    auto dec = [&](int l, int r, int v, bool all = 0) {
        int k = bel[l];
        if (all && !cnt[k]) { tag[k] = min(n, tag[k] + v); return; }
        for (int i = l; i <= r; i++) a[i] = max(1, a[i] - v);
        cnt[k] = 0;
        for (int i = bl[k]; i <= br[k]; i++) {
            if (a[i] < bl[k]) top[i] = a[i];
            else top[i] = top[a[i]], cnt[k]++;
        }
    };
    for (int i = 1; i <= bel[n]; i++) {
        dec(bl[i], br[i], 0);
    }
    auto nxt = [&](int i) {
        return cnt[bel[i]] ? top[i] : max(1, a[i] - tag[bel[i]]);
    };
    for (int _ = 1, op, x, y, z; _ <= q; _++) {
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            scanf("%d", &z);
            if (bel[x] == bel[y]) {
                dec(x, y, z);
            } else {
                dec(x, br[bel[x]], z);
                dec(bl[bel[y]], y, z);
                for (int i = bel[x] + 1; i < bel[y]; i++) {
                    dec(bl[i], br[i], z, 1);
                }
            }
        } else {
            while (x ^ y) {
                if (x < y) swap(x, y);
                if (bel[x] ^ bel[y]) { x = nxt(x); continue; }
                if (nxt(x) == nxt(y)) x = cnt[bel[x]] ? a[x] : max(1, a[x] - tag[bel[x]]);
                else x = nxt(x), y = nxt(y);
            }
            printf("%d\n", x);
        }
    }
    return 0;
}