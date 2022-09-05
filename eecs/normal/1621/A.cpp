#include <bits/stdc++.h>
using namespace std;

int T, n, K;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        if (K > (n + 1) / 2) {
            puts("-1");
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == j && i % 2 == 1 && i <= 2 * K - 1) putchar('R');
                    else putchar('.');
                }
                putchar('\n');
            }
        }
    }
    return 0;
}