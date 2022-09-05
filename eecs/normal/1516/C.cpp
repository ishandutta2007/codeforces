#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, a[maxn];
bitset<2000010> b;

int main() {
    scanf("%d", &n);
    int g = 0, s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), g = __gcd(g, a[i]);
    }
    b.set(0);
    for (int i = 1; i <= n; i++) {
        a[i] /= g, s += a[i];
        b |= (b << a[i]);
    }
    if ((s & 1) || !b.test(s >> 1)) puts("0"), exit(0);
    for (int i = 1; i <= n; i++) if (a[i] & 1) {
        printf("1\n%d\n", i); break;
    }
    return 0;
}