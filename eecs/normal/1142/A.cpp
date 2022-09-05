#include <bits/stdc++.h>
using namespace std;

int n, K, a, b;

int main() {
    scanf("%d %d %d %d", &n, &K, &a, &b);
    long long m = 1LL * n * K;
    long long mn = LLONG_MAX, mx = LLONG_MIN;
    auto chk = [&](long long x) {
        x = (x % K + K) % K;
        for (int i = 0; i < n; i++, x += K) {
            long long d = m / __gcd(m, x);
            mn = min(mn, d), mx = max(mx, d);
        }
    };
    for (int x : {-1, 1}) for (int y : {-1, 1}) {
        chk(a * x + b * y);
    }
    printf("%lld %lld\n", mn, mx);
    return 0;
}