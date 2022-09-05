#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], b[maxn], p[maxn], q[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    iota(p + 1, p + n + 1, 1);
    sort(p + 1, p + n + 1, [&](int x, int y) { return b[x] < b[y]; });
    for (int i = 1; i <= n; i++) {
        q[p[i]] = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[n - q[i] + 1]);
    }
    return 0;
}