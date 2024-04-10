#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, maxC = 1000010;
int n, C, m;
long long mx[maxC], f[maxC];
array<int, 3> a[maxn];

int main() {
    scanf("%d %d", &n, &C);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        mx[a[i][0]] = max(mx[a[i][0]], 1LL * a[i][1] * a[i][2]);
    }
    for (int i = 1; i <= C; i++) if (mx[i]) {
        for (int j = 1; i * j <= C; j++) {
            f[i * j] = max(f[i * j], 1LL * mx[i] * j - 1);
        }
    }
    for (int i = 1; i <= C; i++) {
        f[i] = max(f[i], f[i - 1]);
    }
    scanf("%d", &m);
    while (m--) {
        int d;
        long long h;
        scanf("%d %lld", &d, &h), h *= d;
        int res = lower_bound(f + 1, f + C + 1, h) - f;
        printf("%d ", res > C ? -1 : res);
    }
    return 0;
}