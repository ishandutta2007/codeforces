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
	a %= mod;
	b %= mod;
	ll answer = 0;
	for(int i = 0; (1LL << i) <= a; ++i) {
		if(a & (1LL << i)) {
			answer += b;
			if(answer >= mod) {
				answer -= mod;
			}
		}
		b *= 2;
		if(b >= mod) {
			b -= mod;
		}
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

const int mod = 998244353;

ll exact(ll a, int k) {
	ll r = a;
	while(k > 1) {
		r *= a;
		--k;
	}
	return r;
}

ll my_pow(ll x, int k) {
	ll a = pow(x, 1. / k);
	while(exact(a, k) < x) {
		++a;
	}
	while(exact(a, k) > x) {
		--a;
	}
	if(exact(a, k) == x) {
		return a;
	}
	return -1;
}

int main() {
	int n;
	scanf("%d", &n);
	map<ll, int> mapka;
	vector<ll> still;
	set<ll> primes;
	for(int i = 0; i < n; ++i) {
		ll x;
		scanf("%lld", &x);
		bool done = false;
		for(int k = 4; k >= 2; --k) {
			ll a = my_pow(x, k);
			if(a != -1) {
				mapka[a] += k;
				primes.insert(a);
				done = true;
				break;
			}
		}
		if(done) {
			continue;
		}
		still.push_back(x);
	}
	for(int i = 0; i < (int) still.size(); ++i) {
		for(int j = i + 1; j < (int) still.size(); ++j) {
			if(still[i] != still[j]) {
				ll g = __gcd(still[i], still[j]);
				if(g != 1) {
					primes.insert(g);
				}
			}
		}
	}
	vector<int> cnt(still.size());
	for(int i = 0; i < (int) still.size(); ++i) {
		for(ll p : primes) {
			if(still[i] % p == 0) {
				still[i] /= p;
				++cnt[i];
				++mapka[p];
			}
		}
	}
	map<ll, int> extra;
	for(int i = 0; i < (int) still.size(); ++i) {
		if(still[i] != 1 && cnt[i]) {
			assert(cnt[i] == 1);
			++mapka[still[i]];
		}
		if(cnt[i] == 0) {
			++extra[still[i]];
		}
	}
	int nxt = -1000000000;
	for(auto pp : extra) {
		mapka[nxt++] += pp.second;
		mapka[nxt++] += pp.second;
	}
	//~ while(n--) {
		//~ ll x;
		//~ scanf("%lld", &x);
		//~ auto w = rozklad(x);
		//~ debug() << imie(w);
		//~ for(ll y : w) {
			//~ ++mapka[y];
		//~ }
	//~ }
	debug() << imie(mapka);
	int answer = 1;
	for(auto pp : mapka) {
		int times = pp.second + 1;
		answer = (long long) answer * times % mod;
	}
	printf("%d\n", answer);
}