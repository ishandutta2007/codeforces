#include <bits/stdc++.h>
using namespace std;

int n, a[25];
bitset<1010> b;

int main() {
    scanf("%d", &n);
    b[0] = 1;
    for (int i = 1; i <= 20; i++) {
        b = (b << 1) | (b << 5) | (b << 10) | (b << 50);
        a[i] = b.count();
        if (i == n) printf("%d\n", a[i]), exit(0);
    }
    printf("%lld\n", a[20] + 49LL * (n - 20));
    return 0;
}