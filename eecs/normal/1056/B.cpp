#include <bits/stdc++.h>
using namespace std;

int n, m;
long long ans;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= min(n, m); i++) {
        for (int j = 1; j <= min(n, m); j++) if ((i * i + j * j) % m == 0) {
            ans += 1LL * ((n - i) / m + 1) * ((n - j) / m + 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}