#include <bits/stdc++.h>
using namespace std;

int T, n, K;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        if (!K) {
            for (int i = 0; i < n / 2; i++) {
                printf("%d %d\n", i, n - 1 - i);
            }
        } else if (K < n - 1) {
            printf("%d %d\n", K, n - 1);
            printf("%d %d\n", 0, n - 1 - K);
            for (int i = 1; i < n / 2; i++) {
                if (i != K && n - 1 - i != K) printf("%d %d\n", i, n - 1 - i);
            }
        } else if (n == 4) {
            puts("-1");
        } else {
            printf("%d %d\n", n - 2, n - 1);
            printf("0 1\n2 %d\n3 %d\n", n - 4, n - 3);
            for (int i = 4; i < n / 2; i++) {
                printf("%d %d\n", i, n - 1 - i);
            }
        }
    }
    return 0;
}