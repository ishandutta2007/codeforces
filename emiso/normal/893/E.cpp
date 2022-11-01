#include <bits/stdc++.h>

#define MN 1001000
#define MOD 1000000007
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, t, x, y;
ll ans, fat[MN];

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll rem(ll a, ll b) {
    return (((a - b) % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b % 2) return mul(a, expo(a * a, b >> 1));
    return expo(a * a, b >> 1);
}

ll inv(ll a) {
    return expo(a, MOD - 2);
}

ll nCr(ll n, ll k) {
    if(k > n) return 0;
    return mul(fat[n], inv( mul(fat[k], fat[n-k]) ));
}

ll divisor[MN];

void modified_sieve() {
    for(int i = 1; i < MN; i++)
        divisor[i] = i;

    for(int i = 2; i < MN; i++)
        if(divisor[i] == i)
            for(int j = 2*i; j < MN; j += i)
                divisor[j] = i;
}

vector<pair<ll, ll> > get_prime_divisors(ll x) {
    vector<pair<ll, ll> > ret;
    while(x != 1) {
        if(ret.empty() || ret.back().first != divisor[x]) ret.push_back(pair<ll, ll> (divisor[x], 1));
        else ret.back().second++;
        x /= divisor[x];
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    fat[0] = 1;
    for(int i = 1; i < MN; i++) {
        fat[i] = mul(fat[i-1], i);
    }

    modified_sieve();
    scanf("%lld", &t);

    for(int i=0; i<t; i++) {
        scanf("%lld %lld", &x, &y);
        vector<pair<ll, ll> > divs = get_prime_divisors(x);

        ll ans = 1, y1 = rem(y, 1), actual_ans = 0;
        for(pair<ll, ll> p : divs) {
            ll q = p.second;
            ans = mul(ans, nCr(add(q, y1), y1));
        }

        actual_ans = mul(ans, expo(2, y1));
        printf("%lld\n", actual_ans);
    }

    return 0;
}