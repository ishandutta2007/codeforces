#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, a[maxn], cnt[maxn];
bitset<10010> b[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= cnt[i]; j++) {
            for (int k = 0; k <= n; k++) {
                b[k].reset();
            }
            b[0].set(0);
            int cur = 0;
            for (int k = 1; k <= n; k++) {
                if (a[k] == i && ++cur >= j) continue;
                for (int j = k; j; j--) {
                    b[j] |= (b[j - 1] << a[k]);
                }
            }
            if (!b[j][i * j]) {
                int num = 0;
                for (int l = 1; l <= 100; l++) if (i ^ l) {
                    if (cnt[l] == n - j) num = cnt[l];
                }
                ans = max(ans, j + num);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}