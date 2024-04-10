#include <bits/stdc++.h>
using namespace std;

int T, l, r;

int main() {
    scanf("%d", &T);
    auto calc = [&](long long n) {
        long long ans = 0;
        for (long long i = 1; i <= n; i *= 10) {
            ans += n / i;
        }
        return ans;
    };
    while (T--) {
        scanf("%d %d", &l, &r);
        printf("%lld\n", calc(r) - calc(l));
    }
    return 0;
}