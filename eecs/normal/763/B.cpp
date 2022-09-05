#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n;

int main() {
    scanf("%d", &n);
    puts("YES");
    for (int i = 1, x1, y1, x2, y2; i <= n; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", abs(x1) % 2 * 2 + abs(y1) % 2 + 1);
    }
    return 0;
}