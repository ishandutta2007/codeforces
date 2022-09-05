#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int mn = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        a[n + 1] = 0;
        for (int i = 2; i < n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) a[i + 1] = max(a[i], a[i + 2]), mn++;
        }
        printf("%d\n", mn);
        for (int i = 1; i <= n; i++) printf("%d ", a[i]);
        putchar('\n');
    }
    return 0;
}