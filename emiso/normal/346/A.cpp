#include <bits/stdc++.h>

using namespace std;

int g, x, n, mx;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        g = (g == 0) ? x : __gcd(g, x);
        mx = max(mx, x);
    }
    x = mx / g - n;

    puts((x % 2) ? "Alice" : "Bob");
    return 0;
}