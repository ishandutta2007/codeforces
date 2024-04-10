#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int maxn = 1010;
int w, h, n, x[maxn], y[maxn];
mt19937 rnd(time(0));

int main() {
    scanf("%d %d %d", &w, &h, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    auto calc = [&](ld a, ld b) {
        ld mn = 1e18, sec = mn;
        for (int i = 1; i <= n; i++) {
            ld d = (x[i] - a) * (x[i] - a) + (y[i] - b) * (y[i] - b);
            if (d < mn) sec = mn, mn = d;
            else if (d < sec) sec = d;
        }
        return sec;
    };
    auto get = [&]() {
        return (ld)rnd() / rnd.max();
    };
    double st = clock();
    ld ans = 0;
    while ((clock() - st) / CLOCKS_PER_SEC < 1.5) {
        ld x = get() * w, y = get() * h, v = calc(x, y);
        for (ld T = 0.5; T >= 1e-10; T *= 0.995) {
            ld _x = min((ld)w, max((ld)0, x + (get() - 0.5) * T * w));
            ld _y = min((ld)h, max((ld)0, y + (get() - 0.5) * T * h));
            ld t = calc(_x, _y);
            if (t > v || exp((t - ans) / T) > get()) v = t, x = _x, y = _y;
            ans = max(ans, t);
        }
    }
    printf("%.10Lf\n", sqrtl(ans));
    return 0;
}