#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007ll;

ll binpow(ll x, ll deg) {
    if (deg == 0ll) return 1ll;
    if (deg & 1ll) return (x * binpow(x, deg - 1ll)) % MOD;
    x = binpow(x, deg >> 1ll);
    return (x * x) % MOD;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll n,x,a[100005],sum;

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    for (int i = 0; i < n; ++i) a[i] = sum - a[i];
    sort(a,a+n);
    ll cnt = 1, cur = a[0];
    for (int i = 1; i < n; ++i) {
        bool good = true;
        while (cur < a[i]) {
            if (cnt % x == 0ll) ++cur, cnt /= x;
            else { good = false; break; }
        }
        if (!good) break;
        ++cnt;
    }
    while (cnt % x == 0ll) cnt /= x, ++cur;
    cout << binpow(x, min(cur, sum));

    return 0;
}