#include <bits/stdc++.h>
using namespace std;

int T, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &y);
        if ((x + y) & 1) puts("-1 -1");
        else printf("%d %d\n", x / 2, y / 2 + (x % 2 == 1));
    }
    return 0;
}