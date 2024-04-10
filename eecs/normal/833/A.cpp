#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        long long c = 1LL * a * b;
        long long d = pow(c, 1.0 / 3);
        while ((d + 1) * (d + 1) * (d + 1) <= c) d++;
        if (d * d * d != c || 1LL * b * b % a || 1LL * a * a % b) puts("No");
        else puts("Yes");
    }
    return 0;
}