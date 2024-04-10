#include <bits/stdc++.h>
using namespace std;

int T, n, a, b;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        if (a + b + 2 > n || abs(a - b) > 1) { puts("-1"); continue; }
        int l = 1, r = n;
        for (int i = 1; i <= a + b + 1; i++) {
            if ((i & 1) == (b < a)) printf("%d ", l++);
            else printf("%d ", r--);
        }
        if (((a + b + 1) & 1) == (b < a)) {
            for (int i = l; i <= r; i++) printf("%d ", i);
        } else {
            for (int i = r; i >= l; i--) printf("%d ", i);
        }
        putchar('\n');
    }
    return 0;
}