#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    scanf("%d %d", &a, &b);
    for (int x = 0; x <= 1000; x++) {
        for (int y = 0; y <= 1000; y++) if (x && y && x * x + y * y == a * a) {
            for (int i = 1; i <= 1000; i++) if (!(i * x % y)) {
                int j = -i * x / y;
                if (!j || i == x || j == y) continue;
                if (i * i + j * j == b * b) {
                    puts("YES\n0 0");
                    printf("%d %d\n%d %d\n", x, y, i, j), exit(0);
                }
            }
        }
    }
    puts("NO");
    return 0;
}