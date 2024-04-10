#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, x1, x2;
pair<int, int> c[maxn];

int main() {
    scanf("%d %d %d", &n, &x1, &x2);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i].first), c[i].second = i;
    }
    sort(c + 1, c + n + 1);
    int suf1 = -1, suf2 = -1;
    for (int i = n; i; i--) {
        if (1LL * c[i].first * (n - i + 1) >= x1) { suf1 = i; break; }
    }
    for (int i = n; i; i--) {
        if (1LL * c[i].first * (n - i + 1) >= x2) { suf2 = i; break; }
    }
    for (int i = 1; i <= n; i++) {
        int j = i + (x1 + c[i].first - 1) / c[i].first - 1;
        if (j < n && suf2 > j) {
            puts("Yes");
            printf("%d %d\n", j - i + 1, n - suf2 + 1);
            for (int k = i; k <= j; k++) printf("%d ", c[k].second);
            putchar('\n');
            for (int k = suf2; k <= n; k++) printf("%d ", c[k].second);
            exit(0);
        }
        j = i + (x2 + c[i].first - 1) / c[i].first - 1;
        if (j < n && suf1 > j) {
            puts("Yes");
            printf("%d %d\n", n - suf1 + 1, j - i + 1);
            for (int k = suf1; k <= n; k++) printf("%d ", c[k].second);
            putchar('\n');
            for (int k = i; k <= j; k++) printf("%d ", c[k].second);
            exit(0);
        }
    }
    puts("No");
    return 0;
}