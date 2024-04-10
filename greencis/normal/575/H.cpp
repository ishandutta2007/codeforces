#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007ll;
ll n;

ll factorial(int k) {
    ll ans = 1ll;
    for (int i = 2; i <= k; ++i)
        ans = (ans * ll(i)) % MOD;
    return ans;
}

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a) {
        ll xa = 0, ya = 0;
        ll d = gcd(b % a, a, xa, ya);
        x = ya - (b / a) * xa;
        y = xa;
        return d;
    } else {
        x = 0, y = 1;
        return b;
    }
}

int main()
{
    cin >> n;
    ++n;
    ll ans = factorial(n + n);
    ll f = factorial(n);
    f = (f * f) % MOD;
    if (ans % f == 0) ans /= f;
    else {
        ll xa = 0, ya = 0;
        ll g = gcd(f, MOD, xa, ya);
        ans = xa * (ans / g);
    }
    ans %= MOD;
    ans = (ans + MOD + MOD - 1) % MOD;
    cout << ans;

    return 0;
}