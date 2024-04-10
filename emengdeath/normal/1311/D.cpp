#include <algorithm>
#include <cstdio>
using namespace std;
int t, a, b, c;
int ans = 1e9, ansa, ansb, ansc;
void update(int v, int a, int b, int c) {
    if (v < ans)
        ans = v, ansa = a, ansb= b, ansc = c;
}
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d %d", &a, &b, &c);
        ans = 1e9, ansa, ansb, ansc;
        for (int i = 1; i <= 1e4; i ++)
            for (int j = i; j - i <= b || j - i <= c; j += i) {
                int v = abs(i - a) + abs(j - b);
                int u = (c / j) * j;
                update(v + abs(u - c), i, j, u);
                u = (c + j - 1) / j * j;
                update(v + abs(u - c), i, j, u);
            }
        printf("%d\n%d %d %d\n", ans, ansa, ansb, ansc);
    }
}