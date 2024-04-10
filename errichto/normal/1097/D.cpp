#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

vector<ll> witness = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}; // < 2^64

ll mul(ll a, ll b, ll mod) {
    ll answer = 0;
    a %= mod;
    b %= mod;
    while(a) {
        if(a % 2) {
            answer += b;
            if(answer >= mod) {
                answer -= mod;
            }
        }
        b += b;
        if(b >= mod) {
            b -= mod;
        }
        a /= 2;
    }
    return answer;
	//~ return (__int128) a * b % mod;
}
ll my_pow(ll a, ll b, ll mod) {
	ll res = 1;
	while(b) {
		if(b % 2) res = mul(res, a, mod);
		a = mul(a, a, mod);
		b /= 2;
	}
	return res;
}
bool test(ll n) {
	if(n == 2) return true;
	if(n < 2 || n % 2 == 0) return false;
	ll d = n - 1, s = 0;
	while(d % 2 == 0) {
		d /= 2;
		++s;
	}
	for(auto i : witness) if(i % n) {
		ll x = my_pow(i, d, n);
		if(x == 1) continue;
		bool zlozona = true;
		for(int j = 0; j < s; ++j) {
			if(x == n - 1) {
				zlozona = false;
				break;
			}
			x = mul(x, x, n);
		}
		if(zlozona) return false;
	}
	return true;
}
ll f(ll x, ll mod, ll c) {
	ll y = mul(x, x, mod) + c;
	if(y > mod) y -= mod;
	return y;
}
void rho(ll n, vector<ll> & w) {
	if(n <= 1) return;
	if(test(n)) {
		w.push_back(n);
		return;
	}
	for(ll c = 1; true; ++c) {
		ll x = 2, y = 2, d = 1;
		while(d == 1) {
			x = f(x, n, c);
			y = f( f(y,n,c), n, c);
			d = __gcd(abs(x - y), n);
		}
		if(d < n) {
			rho(d, w);
			rho(n / d, w);
			return;
		}
	}
}
vector<ll> rozklad(ll n) {
	vector<ll> w;
	for(int i = 2; i <= 100; ++i) while(n % i == 0) {
		n /= i;
		w.push_back(i);
	}
	rho(n, w);
	sort(w.begin(), w.end());
	return w;
}

const int mod = 1e9 + 7;

int my_pow(int a, int b) {
    int r = 1;
    while(b) {
        if(b % 2) {
            r = (ll) r * a % mod;
        }
        a = (ll) a * a % mod;
        b /= 2;
    }
    return r;
}
int my_inv(int a) {
    return my_pow(a, mod - 2);
}

const int nax = 55;
int pre_inv[nax];
            

int main() {
    for(int i = 1; i < nax; ++i) {
        pre_inv[i] = my_inv(i);
    }
    pre_inv[0] = 1;
	ll n;
    int k;
    cin >> n >> k;
    vector<ll> primes = rozklad(n);
    debug() << imie(primes);
    ll answer = 1;
    debug() << imie(pre_inv[2]);
    for(int it = 0; it < (int) primes.size(); ++it) {
        ll prime = primes[it];
        int cnt = 1;
        while(it + 1 < (int) primes.size() && primes[it] == primes[it+1]) {
            ++cnt;
            ++it;
        }
        debug() << imie(prime) imie(cnt);
        vector<int> dp(cnt + 1);
        dp[cnt] = 1;
        
        for(int rep = 0; rep < k; ++rep) {
            int suf = 0;
            for(int i = cnt; i >= 0; --i) {
                suf = (suf + (ll) dp[i] * pre_inv[i+1]) % mod;
                dp[i] = suf;
            }
        }
        
        int total = 0;
        int mul = 1;
        for(int i = 0; i <= cnt; ++i) {
            total = (total + (ll) mul * dp[i]) % mod;
            mul = (ll) mul * (prime % mod) % mod;
        }
        debug() << imie(dp);
        answer = (ll) answer * total % mod;
    }
    printf("%lld\n", answer);
}