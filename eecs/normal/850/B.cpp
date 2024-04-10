#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, x, y, a[maxn], ok[maxn];
long long ans = LLONG_MAX;
mt19937 rnd(time(0));

int main() {
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    double st = clock();
    auto chk = [&](int g) {
        if (ok[g]) return;
        ok[g] = 1;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += min(1LL * x, 1LL * y * (a[i] % g ? g - a[i] % g : 0));
        }
        ans = min(ans, sum);
    };
    auto fact = [&](int x) {
        for (int i = 2; i * i <= x; i++) if (!(x % i)) {
            chk(i);
            while (!(x % i)) x /= i;
        }
        if (x > 1) chk(x);
    };
    chk(2);
    while ((clock() - st) / CLOCKS_PER_SEC < 1.5) {
        int i = rnd() % n + 1;
        if (a[i] - 1 > 1) fact(a[i] - 1);
        if (a[i] > 1) fact(a[i]);
        fact(a[i] + 1);
    }
    printf("%lld\n", ans);
    return 0;
}