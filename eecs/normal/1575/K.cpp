#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;

int qp(int x, long long y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    int n, m, K, r, c;
    scanf("%d %d %d %d %d", &n, &m, &K, &r, &c);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    long long t = 1LL * max(0, min(x1 + r - 1, x2 + r - 1) - max(x1, x2) + 1)
        * max(0, min(y1 + c - 1, y2 + c - 1) - max(y1, y2) + 1);
    long long z = 1LL * n * m - 2LL * r * c + t;
    z += 1LL * r * c - t;
    if (x1 == x2 && y1 == y2) z = 1LL * n * m;
    printf("%d\n", qp(K, z));
    return 0;
}