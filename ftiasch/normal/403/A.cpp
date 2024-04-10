#include <cstdio>

int main() {
    int tests;
    scanf("%d", &tests);
    while (tests -- ) {
        int n, p;
        scanf("%d%d", &n, &p);
        printf("%d %d\n", 1, 2);
        for (int i = 3; i <= n; ++ i) {
            printf("%d %d\n%d %d\n", 1, i, 2, i);
        }
        int left = p + 3;
        for (int i = 3; i <= n; ++ i) {
            for (int j = i + 1; j <= n; ++ j) {
                if (left > 0) {
                    left --;
                    printf("%d %d\n", i, j);
                }
            }
        }
    }
    return 0;
}