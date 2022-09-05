#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, s, a[maxn];

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (a[i] > s) ans += a[i] - s;
    }
    ans += abs(a[n / 2 + 1] - s);
    for (int i = n / 2 + 2; i <= n; i++) {
        if (a[i] < s) ans += s - a[i];
    }
    printf("%lld\n", ans);
    return 0;
}