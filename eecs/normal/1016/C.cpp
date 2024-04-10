#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, a[maxn], b[maxn];
long long ans, sa1[maxn], sa2[maxn], sb1[maxn], sb2[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sa1[i] = sa1[i - 1] + a[i];
        sa2[i] = sa2[i - 1] + 1LL * i * a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        sb1[i] = sb1[i - 1] + b[i];
        sb2[i] = sb2[i - 1] + 1LL * i * b[i];
    }
    int cur = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            long long x = sum;
            /* for (int j = i; j <= n; j++) {
                x += 1LL * a[j] * (j - i + cur);
            }
            for (int j = n; j >= i; j--) {
                x += 1LL * b[j] * (n - i + 1 + cur + n - j);
            } */
            x += sa2[n] - sa2[i - 1];
            x += 1LL * (cur - i) * (sa1[n] - sa1[i - 1]);
            x -= sb2[n] - sb2[i - 1];
            x += 1LL * (cur + n + n - i + 1) * (sb1[n] - sb1[i - 1]);
            ans = max(ans, x);
            sum += 1LL * a[i] * cur++;
            sum += 1LL * b[i] * cur++;
        } else {
            long long x = sum;
            /* for (int j = i; j <= n; j++) {
                x += 1LL * b[j] * (j - i + cur);
            }
            for (int j = n; j >= i; j--) {
                x += 1LL * a[j] * (n - i + 1 + cur + n - j);
            } */
            x += sb2[n] - sb2[i - 1];
            x += 1LL * (cur - i) * (sb1[n] - sb1[i - 1]);
            x -= sa2[n] - sa2[i - 1];
            x += 1LL * (cur + n + n - i + 1) * (sa1[n] - sa1[i - 1]);
            ans = max(ans, x);
            sum += 1LL * b[i] * cur++;
            sum += 1LL * a[i] * cur++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}