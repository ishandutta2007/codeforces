#include <bits/stdc++.h>
using namespace std;
int n, d, m;
int a[100010];
long long ans, sum[100010];
int main() {
    scanf("%d%d%d", &n, &d, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    int pos = n + 1;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] > m) {
            pos = i;
            break;
        }
    }
    ans = sum[pos - 1];
    for (int i = 1; i <= n - pos + 1; i++) {
        long long need = 1ll * (i - 1) * d;
        need -= n - pos + 1 - i;
        need = max(need, 0ll);
        if (need > pos - 1) break;
        ans = max(ans, sum[pos - 1] - sum[need] + sum[n] - sum[n - i]);
    }
    cout << ans << endl;
}