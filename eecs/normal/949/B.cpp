#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, q, x;

ll solve(ll x, ll n) {
    if (x & 1) {
        return (x + 1) >> 1;
    } else if (!(n & 1)) {
        return solve(x >> 1, n >> 1) + ((n + 1) >> 1);
    } else if ((x - 2) >> 1) {
        return solve((x - 2) >> 1, n >> 1) + ((n + 1) >> 1);
    } else {
        return solve(n >> 1, n >> 1) + ((n + 1) >> 1);
    }
}

int main() {
    scanf("%lld %lld", &n, &q);
    while (q--) {
        scanf("%lld", &x);
        printf("%lld\n", solve(x, n));
    }
    return 0;
}