#include <bits/stdc++.h>
using namespace std;
int n, a[100010];
inline int check(int x) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return 1;
    return 0;
}
void rmain() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) scanf("%d", a + i), sum += a[i];
    if (check(sum)) {
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) printf("%d%c", i, " \n"[i == n]);
        return;
    }
    for (int i = 1; i <= n; i++) if (check(sum - a[i])) {
        printf("%d\n", n - 1);
        for (int j = 1; j <= n; j++) if (i != j) printf("%d ", j);
        puts("");
        return;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}