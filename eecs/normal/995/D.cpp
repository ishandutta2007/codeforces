#include <bits/stdc++.h>
using namespace std;

int n, q, a[1 << 18];
long long s;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < 1 << n; i++) {
        scanf("%d", &a[i]), s += a[i];
    }
    printf("%.6f\n", 1.0 * s / (1 << n));
    while (q--) {
        int p, v; scanf("%d %d", &p, &v);
        s += v - a[p], a[p] = v;
        printf("%.6f\n", 1.0 * s / (1 << n));
    }
    return 0;
}