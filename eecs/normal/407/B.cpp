#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010, P = 1000000007;
int n, p[maxn], f[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    f[1] = 2;
    for (int i = 2; i <= n; i++) {
        f[i] = (2LL * f[i - 1] - f[p[i] - 1] + P + 2) % P;
    }
    printf("%d\n", f[n]);
    return 0;
}