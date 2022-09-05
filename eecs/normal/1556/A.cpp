#include <bits/stdc++.h>
using namespace std;

int T, c, d;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &c, &d);
        if (c % 2 != d % 2) {
            puts("-1");
        } else if (!c && !d) {
            puts("0");
        } else if (abs(c) == abs(d)) {
            puts("1");
        } else {
            puts("2");
        }
    }
    return 0;
}