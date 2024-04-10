#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n * (n - 1) / 2 % 2) puts("NO"), exit(0);
    puts("YES");
    auto op = [&](int x, int y) {
        printf("%d %d\n", x, y);
    };
    for (int i = 2; i <= n; i += 2) {
        op(i - 1, i);
        if (n % 4 == 1) op(i, n);
        for (int j = 1; j + 1 < i; j += 2) {
            op(j, i), op(j + 1, i - 1), op(j, i - 1), op(j + 1, i);
        }
    }
    if (n % 4 == 1) {
        for (int i = n - 2; i > 0; i -= 2) op(i, n);
    }
    return 0;
}