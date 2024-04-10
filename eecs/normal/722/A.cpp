#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d, mn = INT_MAX;
array<int, 4> ans;

int main() {
    scanf("%d", &n);
    scanf("%1d%1d:%1d%1d", &a, &b, &c, &d);
    if (n == 12) {
        for (int h = 1; h <= 12; h++) {
            for (int m = 0; m < 60; m++) {
                int w = h / 10, x = h % 10, y = m / 10, z = m % 10;
                int t = (w != a) + (x != b) + (y != c) + (z != d);
                if (t < mn) mn = t, ans = {w, x, y, z};
            }
        }
    } else {
        for (int h = 0; h <= 23; h++) {
            for (int m = 0; m < 60; m++) {
                int w = h / 10, x = h % 10, y = m / 10, z = m % 10;
                int t = (w != a) + (x != b) + (y != c) + (z != d);
                if (t < mn) mn = t, ans = {w, x, y, z};
            }
        }
    }
    printf("%d%d:%d%d\n", ans[0], ans[1], ans[2], ans[3]);
    return 0;
}