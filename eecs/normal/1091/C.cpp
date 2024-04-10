#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    set<long long> S;
    auto chk = [&](int x) {
        S.insert(x + 1LL * x * (x - 1) / 2 * (n / x));
    };
    for (int i = 1; i * i <= n; i++) if (!(n % i)) {
        chk(i), chk(n / i);
    }
    for (long long x : S) printf("%lld ", x);
    return 0;
}