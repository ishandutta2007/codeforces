#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n;
double ans, prob = 1, cur[maxn], p[maxn];

int main() {
    scanf("%d", &n);
    if (n == 1) puts("1"), exit(0);
    double prob = 1;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        p[i] = cur[i] = (100 - x) / 100.0, prob *= 1 - p[i];
    }
    ans = n + 1 - prob;
    for (int _ = 1; _ <= 300000; _++) {
        double foo = prob; int bar;
        for (int i = 1; i <= n; i++) {
            double baz = prob / (1 - cur[i]) * (1 - cur[i] * p[i]);
            if (baz > foo) foo = baz, bar = i;
        }
        ans += 1 - (prob = foo), cur[bar] *= p[bar];
    }
    printf("%.10f\n", ans);
    return 0;
}