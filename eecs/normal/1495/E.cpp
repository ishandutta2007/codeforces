#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5000010, P = 1000000007;
int n, m, a[maxn], b[maxn], t[maxn];
ll sum[2], cnt, ans = 1;

namespace gen {
int seed, base;

int rnd() {
    int t = seed;
    seed = (1LL * seed * base + 233) % P;
    return t;
}

void init() {
    scanf("%d %d", &n, &m);
    for (int _ = 1, p, k, $ = 0; _ <= m; _++) {
        scanf("%d %d %d %d", &p, &k, &seed, &base);
        while ($ < p) t[++$] = rnd() % 2, a[$] = rnd() % k + 1;
    }
}
}  // namespace gen

int main() {
    gen::init();
    for (int i = 1; i <= n; i++) {
        sum[t[i]] += a[i];
    }
    if (sum[0] > sum[1]) {
        for (int i = 1; i <= n; i++) {
            t[i] ^= 1;
        }
    }
    if (t[1]) a[1]--, b[1]++;
    for (int i = 1; i <= n; i++) {
        if (!t[i]) {
            cnt += a[i], b[i] = a[i];
        } else {
            ll v = min((ll)a[i], cnt);
            cnt -= v, a[i] -= v, b[i] += v;
        }
    }
    for (int i = 1; i <= n; i++) if (t[i]) {
        ll v = min(ll(a[i]), cnt);
        cnt -= v, b[i] += v;
    }
    for (int i = 1; i <= n; i++) {
        ll v = (b[i] ^ (1LL * i * i)) + 1;
        (ans *= v % P) %= P;
    }
    printf("%lld\n", ans);
    return 0;
}