#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int n, L, R, f[maxn];
array<int, 2> a[maxn];

int main() {
    scanf("%d %d %d", &n, &L, &R);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][0]), s += a[i][0];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][1]);
    }
    sort(a + 1, a + n + 1, [&](array<int, 2> p, array<int, 2> q) {
        return p[1] < q[1] || p[1] == q[1] && p[0] > q[0];
    });
    int o = L;
    L = s - R, R = s - o;
    memset(f, -0x3f, sizeof(f)), f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= a[i][0]; j--) {
            f[j] = max(f[j], f[j - a[i][0]] + (a[i][1] && L <= j && j <= R));
        }
    }
    printf("%d\n", *max_element(f + 1, f + s + 1));
    return 0;
}