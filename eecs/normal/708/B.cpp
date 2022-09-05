#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    auto get = [&](int x) {
        int y = max(0, (int)sqrt(x) - 1);
        while (y * (y - 1) / 2 < x) y++;
        if (y == 1) y = 0;
        if (y * (y - 1) / 2 == x) return y;
        return -1;
    };
    a = get(a), d = get(d);
    if (!~a || !~d)  puts("Impossible"), exit(0);
    if (!a && !b && !c && !d) puts("0"), exit(0);
    if (!a && !d && (b || c)) a++, d++;
    if (!a && d && b + c != 1LL * a * d) a++;
    else if (a && !d && b + c != 1LL * a * d) d++;
    auto chk = [&](int a, int b, int c, int d) {
        if (a < 0 || b < 0 || c < 0 || d < 0) return 0;
        if (b + c != 1LL * a * d) return 0;
        return 1;
    };
    function<void(int, int, int, int)> solve = [&](int a, int b, int c, int d) {
        if (!a && !b && !c && !d) exit(0);
        if (!chk(a, b, c, d)) puts("Impossible"), exit(0);
        if (chk(a - 1, b - d, c, d)) putchar('0'), solve(a - 1, b - d, c, d);
        else putchar('1'), solve(a, b, c - a, d - 1);
    };
    solve(a, b, c, d);
    return 0;
}