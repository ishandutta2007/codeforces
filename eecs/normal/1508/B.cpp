#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int T, n;
ll K, f[maxn], g[maxn];

int main() {
    scanf("%d", &T);
    f[0] = f[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        f[i] = f[i - 1] << 1;
        if (f[i] > (ll)1e18) f[i] = (ll)1e18;
    }
    for (int i = 1; i <= 100000; i++) {
        g[i] = g[i - 1] + f[i];
        if (g[i] > (ll)1e18) g[i] = (ll)1e18;
    }
    while (T--) {
        scanf("%d %lld", &n, &K);
        if (f[n] < K) { puts("-1"); continue; }
        for (int i = 1; i <= n; i++) {
            int lst = i - 1;
            int l = lst + 1, r = n, v;
            while (l <= r) {
                int mid = (l + r) >> 1;
                ll s = f[n - i + 1 - (mid - lst)];
                // n - i + 1 - 1
                // n - i + 1 - (mid - lst)
                // ll s2 = 0;
                // for (int j = lst + 1; j <= mid; j++) {
                //     s2 += f[n - i + 1 - (j - lst)];
                // }
                if (s >= (K + g[mid - lst] - 1) / g[mid - lst]) r = (v = mid) - 1;
                else l = mid + 1;
            }
            for (int j = lst + 1; j < v; j++) {
                K -= f[n - i + 1 - (j - lst)];
            }
            for (int j = i; j < i + v - lst; j++) {
                printf("%d ", v - (j - i));
            }
            i = i + v - lst - 1;
        }
        putchar('\n');
    }
    return 0;
}