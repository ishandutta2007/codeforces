#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 998244353;
int T, n, tot, a[maxn], f[1010], g[1010], cand[1010], _tot, _cand[1010];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        a[n + 1] = 100001, tot = 0;
        for (int i = 1, nxt; i <= a[n + 1]; i = nxt + 1) {
            nxt = a[n + 1] / (a[n + 1] / i);
            cand[++tot] = i;
            if (!(a[n + 1] % nxt) && i < nxt) cand[++tot] = nxt;
        }
        fill(f + 1, f + tot + 1, 0);
        for (int i = n; i; i--) {
            _tot = 0;
            for (int j = 1, nxt; j <= a[i]; j = nxt + 1) {
                nxt = a[i] / (a[i] / j);
                _cand[++_tot] = j;
                if (!(a[i] % nxt) && j < nxt) _cand[++_tot] = nxt;
            }
            copy(f + 1, f + tot + 1, g + 1);
            fill(f + 1, f + _tot + 1, 0), f[1] = 1;
            for (int j = 1, p = 1; j <= tot; j++) {
                while (a[i] / _cand[p] + (a[i] % _cand[p] > 0) > a[i + 1] / cand[j]) p++;
                (f[p] += g[j]) %= P;
            }
            swap(tot, _tot);
            for (int j = 1; j <= tot; j++) {
                swap(cand[j], _cand[j]);
                ans = (ans + 1LL * i * f[j] % P * (cand[j] - 1)) % P;
            }
        }
        /* for (int i = n; i; i--) {
            int lst = INT_MAX;
            for (int j = i; j; j--) {
                int p = 1;
                while (a[j] / p + (a[j] % p > 0) > lst) p++;
                ans += (p - 1) * j, lst = a[j] / p;
            }
        } */
        printf("%d\n", ans);
    }
    return 0;
}