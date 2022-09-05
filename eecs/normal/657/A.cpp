#include <bits/stdc++.h>
using namespace std;

int n, d, h;

int main() {
    scanf("%d %d %d", &n, &d, &h);
    if (h + h < d) puts("-1"), exit(0);
    if (n > 2 && d == 1) puts("-1"), exit(0);
    if (d == h) {
        for (int i = 1; i <= h; i++) {
            printf("%d %d\n", i, i + 1);
        }
        for (int i = h + 2; i <= n; i++) {
            printf("2 %d\n", i);
        }
        exit(0);
    }
    for (int i = 1; i <= h; i++) {
        printf("%d %d\n", i, i + 1);
    }
    for (int i = h + 2; i <= d + 1; i++) {
        if (i == h + 2) printf("1 %d\n", i);
        else printf("%d %d\n", i - 1, i);
    }
    for (int i = d + 2; i <= n; i++) {
        printf("1 %d\n", i);
    }
    return 0;
}