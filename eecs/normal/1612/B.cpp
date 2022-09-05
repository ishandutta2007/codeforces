#include <bits/stdc++.h>
using namespace std;

int T, n, a, b, p[110];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        p[1] = a, p[n] = b;
        bool flag = 1;
        int k = n;
        for (int i = 2; i <= n / 2; i++) {
            while (k == a || k == b) k--;
            flag &= k >= a, p[i] = k--;
        }
        for (int i = n / 2 + 1; i < n; i++) {
            while (k == a || k == b) k--;
            flag &= k <= b, p[i] = k--;
        }
        if (!flag) { puts("-1"); continue; }
        for (int i = 1; i <= n; i++) printf("%d ", p[i]);
        putchar('\n');
    }
    return 0;
}