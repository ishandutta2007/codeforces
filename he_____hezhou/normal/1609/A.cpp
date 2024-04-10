#include <bits/stdc++.h>
using namespace std;
int T, n;
int a[20];
inline void rmain() {
    long long qwq = 1;
    scanf("%d", &n);
    int sum = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        while (a[i] % 2 == 0) qwq *= 2, a[i] /= 2;
        sum += a[i];
        mx = max(mx, a[i]);
    }
    sum -= mx;
    printf("%lld\n", sum + mx * qwq);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}