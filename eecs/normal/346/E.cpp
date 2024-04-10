#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll a, n, p, h;

ll solve(ll a, ll n, ll p) {
    if (a * n < p) return max(a, p - a * n);
    ll z = a * n / p;
    if (a * n % p < p / a * a - a) z--;
    return solve((p + a - 1) / a * a - p, z, a);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld %lld", &a, &n, &p, &h);
        if ((a %= p) <= h) puts("YES");
        else if (a * n <= p) puts(h >= a ? "YES" : "NO");
        else puts(solve(a, n, p) <= h ? "YES" : "NO");
    }
    return 0;
}