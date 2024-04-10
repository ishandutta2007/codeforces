#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, ans, a[maxn], cnt[maxn * 2], mp[maxn * 205];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int k = -100; k <= 100; k++) {
        for (int i = 1; i <= n; i++) {
            ans = max(ans, ++mp[a[i] + i * k + n * 100]);
        }
        for (int i = 1; i <= n; i++) {
            mp[a[i] + i * k + n * 100]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] + (j - i) * 100 > maxn && a[i] - (j - i) * 100 < -maxn) break;
            if ((a[j] - a[i]) % (j - i) == 0) ans = max(ans, ++cnt[(a[j] - a[i]) / (j - i) + maxn] + 1);
        }
        for (int j = i + 1; j <= n; j++) {
            if (a[i] + (j - i) * 100 > maxn && a[i] - (j - i) * 100 < -maxn) break;
            if ((a[j] - a[i]) % (j - i) == 0) cnt[(a[j] - a[i]) / (j - i) + maxn]--;
        }
    }
    printf("%d\n", n - ans);
    return 0;
}