#include <bits/stdc++.h>
using namespace std;

int la, ra, ta;
int lb, rb, tb;

int main() {
    scanf("%d %d %d", &la, &ra, &ta);
    scanf("%d %d %d", &lb, &rb, &tb);
    auto intersect = [&](int a, int c) {
        int b = a + ra - la, d = c + rb - lb;
        return max(0, min(b, d) - max(a, c) + 1);
    };
    int g = __gcd(ta, tb);
    int x = la % g, y = lb % g;
    printf("%d\n", max({intersect(x, y), intersect(x - g, y), intersect(x + g, y)}));
    return 0;
}