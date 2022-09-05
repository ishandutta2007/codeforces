#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 1e9 + 7;
int n, s, p = 1, a[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), p = 1LL * p * i % P;
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1, j; i <= n; i = j) {
        for (j = i + 1; a[i] == a[j]; j++);
        if (i > 1) s = (s + 1LL * p * qp(j - 1, P - 2) % P * (j - i) % P * a[i]) % P;
    }
    printf("%d\n", s);
    return 0;
}