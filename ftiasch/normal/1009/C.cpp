#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long sum = 0;
    while (m --) {
        int x, d;
        scanf("%d%d", &x, &d);
        sum += 1LL * x * n;
        if (d > 0) {
            sum += 1LL * d * (n - 1) * n / 2;
        } else {
            int l1 = (n - 1) >> 1;
            int l2 = n - 1 - l1;
            sum += 1LL * d * (l1 + 1) * l1 / 2;
            sum += 1LL * d * (l2 + 1) * l2 / 2;
        }
    }
    printf("%.9f\n", 1.0 * sum / n);
}