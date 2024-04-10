#include <bits/stdc++.h>
using namespace std;

int T;
long long p, q, b;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &p, &q, &b);
        long long g = __gcd(p, q);
        p /= g, q /= g;
        while (1) {
            b = __gcd(b, q);
            if (b == 1) break;
            q /= b;
        }
        puts(q == 1 ? "Finite" : "Infinite");
    }
    return 0;
}