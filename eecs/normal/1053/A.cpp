#include <bits/stdc++.h>
using namespace std;

int n, m, K;

int main() {
    scanf("%d %d %d", &n, &m, &K);
    if (2LL * n * m % K) puts("NO"), exit(0);
    long long x = 2LL * n * m / K;
    puts("YES");
    printf("0 0\n");
    if (n < m) {
        int a = n, d = (x + a - 1) / a;
        int b = 1, c = 1LL * a * d - x;
        printf("%d %d\n%d %d\n", a, b, c, d);
    } else {
        int b = m, c = (x + b - 1) / b;
        int a = 1, d = 1LL * b * c - x;
        printf("%d %d\n%d %d\n", a, b, c, d);
    }
    return 0;
}