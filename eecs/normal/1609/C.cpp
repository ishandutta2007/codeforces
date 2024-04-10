#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, e, a[maxn];
bool ban[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &e);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), ban[i] = 0;
            int cnt = 0;
            for (int j = 2; j * j <= a[i]; j++) if (!(a[i] % j)) {
                cnt++, a[i] /= j;
                if (!(a[i] % j)) ban[i] = 1;
            }
            if (a[i] > 1) cnt++;
            if (cnt > 1) ban[i] = 1;
        }
        long long ans = 0;
        for (int rem = 0; rem < e; rem++) {
            int cur = 0, num = 0;
            for (int i = !rem ? e : rem, j = i; i <= n; i += e) {
                cur += ban[i], num += a[i] > 1;
                while (j <= n && (cur || num > 1)) {
                    cur -= ban[j], num -= a[j] > 1, j += e;
                }
                ans += max(0, (i - j) / e);
            }
            for (int i = !rem ? e : rem; i <= n; i += e) if (a[i] == 1 && !ban[i]) {
                int j = i;
                while (j <= n && a[j] == 1 && !ban[j]) j += e;
                int len = (j - i) / e;
                ans -= 1LL * len * (len - 1) / 2;
                i = j - e;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}