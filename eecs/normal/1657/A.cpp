#include <bits/stdc++.h>
using namespace std;

int T, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &y);
        int t = x * x + y * y, z = 0;
        while (z * z < t) z++;
        if (!x && !y) puts("0");
        else if (z * z == t) puts("1");
        else puts("2");
    }
    return 0;
}