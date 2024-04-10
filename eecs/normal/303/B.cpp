#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, a, b;

int main() {
    scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b);
    int g = __gcd(a, b);
    a /= g, b /= g;
    int t = min(n / a, m / b);
    int x1 = 0, y1 = 0;
    if (x1 + t * a <= x) x1 += x - x1 - t * a;
    x1 += max(0, min(n - x1 - t * a, x - (t * a + 1) / 2 - x1));
    if (y1 + t * b <= y) y1 += y - y1 - t * b;
    y1 += max(0, min(m - y1 - t * b, y - (t * b + 1) / 2 - y1));
    printf("%d %d %d %d\n", x1, y1, x1 + t * a, y1 + t * b);
    return 0;
}