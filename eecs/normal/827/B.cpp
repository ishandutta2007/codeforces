#include <bits/stdc++.h>
using namespace std;

int n, K;

int main() {
    scanf("%d %d", &n, &K);
    if (n == 3 && K == 2) {
        puts("2\n1 2\n2 3"), exit(0);
    }
    int m = n - 1, t = m / K;
    printf("%d\n", 2 * t + (m % K > 0) + (m % K > 1));
    int tot = 1;
    for (int i = 0; i < K; i++) {
        int num = t + (m % K > i);
        printf("1 %d\n", tot + 1);
        for (int j = 1; j < num; j++) {
            printf("%d %d\n", tot + j, tot + j + 1);
        }
        tot += num;
    }
    return 0;
}