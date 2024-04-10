#include <bits/stdc++.h>
#define MN 61

using namespace std;

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
            } else mobius[i * primes[j]] = - mobius[i];
        }
    }
}

typedef long long ll;

bool mypow(ll b, ll e, ll n) {
    ll res = 1;
    for(int i = 1; i < e; i++) res *= b;
    if( (long double) res * b > (long double) n) return false;
    return true;
}

int main() {
    sieve();
    ll t, n;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        ll ans = n - 1;

        for(int i = 2; i < MN; i++) {
            if(!mobius[i]) continue;
            ll tmp = pow(n, (long double) 1.0/i) + 0.1;
            if(!mypow(tmp, i, n)) tmp--;
            ans += mobius[i] * (tmp - 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}