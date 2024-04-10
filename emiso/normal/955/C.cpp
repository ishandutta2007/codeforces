#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define MN 101
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, l, r;

vector <bool> is_prime(MN, 1);
vector <int> primes, mobius(MN);

void sieve() {
    is_prime[0] = is_prime[1] = 0;
    mobius[1] = 1;

    for(int i = 2; i < MN; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            mobius[i] = -1;
        }
        for(int j = 0; j < primes.size() && i * primes[j] < MN; j++) {
            is_prime[i * primes[j]] = 0;
            if(i % primes[j] == 0) {
                mobius[i * primes[j]] = 0;
                break;
            }
            else mobius[i * primes[j]] = - mobius[i];
        }
    }
}

#define INF 1000000000000000001
ll mul(ll a, ll b) {
    long double A = a, B = b;
    if(A * B > INF) return INF;
    else return a * b;
}

ll expo(ll a, ll b) {
    if(a == 2) return 1LL << b;
    if(!b) return 1;
    if(a >= INF) return INF;
    if(b % 2) return mul(a, expo(mul(a, a), b >> 1));
    return expo(mul(a, a), b >> 1);
}

ll solve(ll x) {
    if(x < 2) return x;
    ll ret = 0, last = min(x, 1000000000LL);

    for(ll pot = 2; pot < 60; pot++) {
        if(mobius[pot] == 0) continue;
        ll l = 1, r = last;
        while(l < r) {
            ll m = (l + r + 1) / 2;
            ll res = expo(m, pot);
            if(res <= x) l = m;
            else r = m - 1;
        }
        last = l;
        l--;
        ret -= (l * mobius[pot]);
    }

    return ret + 1;
}

int main() {
    sieve();
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", solve(r) - solve(l-1));
    }
    return 0;
}