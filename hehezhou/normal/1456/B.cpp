#include <bits/stdc++.h>
using namespace std;
const int inf = 100000000;
int n;
int a[100010];
int sum[100010];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ a[i];
    if (n >= 100) return puts("1"), 0;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++) {
                if ((sum[k] ^ sum[j]) < (sum[j] ^ sum[i])) ans = min(ans, k - i - 2);
            }
    if (ans > n) ans = -1;
    return cout << ans << endl, 0;
}