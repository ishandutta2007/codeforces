#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            puts("1");
        } else if (n % 3 != 1) {
            int cur = 0, num = 2;
            while (cur < n) {
                printf("%d", num), cur += num;
                num = 3 - num;
            }
            putchar('\n');
        } else {
            int cur = 0, num = 1;
            while (cur < n) {
                printf("%d", num), cur += num;
                num = 3 - num;
            }
            putchar('\n');
        }
    }
    return 0;
}