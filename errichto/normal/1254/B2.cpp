#include <bits/stdc++.h>
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
 
using ll = long long;



const ll INF = 1e18L + 5;

int main() {
	int n;
	scanf("%d", &n);
	vector<ll> in(n);
	ll sum = 0;
	for(ll& x : in) {
		scanf("%lld", &x);
		sum += x;
	}
	ll answer = INF;
	vector<ll> divisors;
	for(ll i = 2; i * i <= sum; ++i) {
		if(sum % i == 0) {
			divisors.push_back(i);
		}
		while(sum % i == 0) {
			sum /= i;
		}
	}
	if(sum > 1) {
		divisors.push_back(sum);
	}
	for(ll divisor : divisors) {
		//~ if(divisor == 1) {
			//~ continue;
		//~ }
		ll pref = 0;
		ll maybe = 0;
		for(ll x : in) {
			pref += x;
			pref %= divisor;
			maybe += min(pref, (divisor - pref) % divisor);
		}
		answer = min(answer, maybe);
	}
	if(answer == INF) {
		answer = -1;
	}
	printf("%lld\n", answer);
}