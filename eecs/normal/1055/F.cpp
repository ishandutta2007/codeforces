#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010;
int n, tot, ord[maxn], tmp[maxn], pl[maxn], pr[maxn], from[maxn][2], to[maxn][2];
ll K, ans, a[maxn];

ll read() {
    ll x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x;
}

int main() {
    n = read(), K = read();
    for (int i = 2, p; i <= n; i++) {
        p = read(), a[i] = read();
        a[i] ^= a[p];
    }
    iota(ord + 1, ord + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pl[i] = 1, pr[i] = n;
    }
    for (int i = 61; ~i; i--) {
        int tot = 0;
        for (int j = 1, k; j <= n; j = k) {
            for (k = j; k <= n && (a[ord[j]] >> (i + 1)) == (a[ord[k]] >> (i + 1)); k++);
            for (int c : {0, 1}) {
                from[j][c] = tot + 1;
                for (int l = j; l < k; l++) {
                    if ((a[ord[l]] >> i & 1) == c) tmp[++tot] = ord[l];
                }
                to[j][c] = tot;
            }
        }
        copy(tmp + 1, tmp + n + 1, ord + 1);
        ll t = 0;
        for (int j = 1; j <= n; j++) if (pl[j] <= pr[j]) {
            int c = a[j] >> i & 1;
            t += to[pl[j]][c] - from[pl[j]][c] + 1;
        }
        int flag = 0;
        if (t < K) K -= t, ans |= 1LL << i, flag = 1;
        for (int j = 1; j <= n; j++) if (pl[j] <= pr[j]) {
            int c = (a[j] >> i & 1) ^ flag;
            pr[j] = to[pl[j]][c], pl[j] = from[pl[j]][c];
        }
    }
    printf("%lld\n", ans);
    return 0;
}