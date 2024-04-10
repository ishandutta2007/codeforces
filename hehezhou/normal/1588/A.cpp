#include <bits/stdc++.h>
using namespace std;
int T;
int n, a[100010], b[100010];
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) if (a[i] > b[i] || a[i] < b[i] - 1) return puts("NO"), void();
    puts("YES");
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}