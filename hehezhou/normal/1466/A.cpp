#include <bits/stdc++.h>
using namespace std;
int n, x[110];
int a[10010], cnt;
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", x + i);
    cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) a[++cnt] = x[j] - x[i];
    sort(a + 1, a + 1 + cnt);
    printf("%d\n", unique(a + 1, a + 1 + cnt) - a - 1);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) rmain();
}