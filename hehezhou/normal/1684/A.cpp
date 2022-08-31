#include <bits/stdc++.h>
using namespace std;
void rmain() {
    int n;
    scanf("%d", &n);
    if (n < 100) return printf("%d\n", n % 10), void();
    int ans = 9;
    while (n) ans = min(ans, n % 10), n /= 10;
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}