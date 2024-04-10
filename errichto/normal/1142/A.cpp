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

using ll = long long;



int main() {
	int n, k, a, b;
	scanf("%d%d%d%d", &n, &k, &a, &b);
	ll small = (ll) n * k, big = 0;
	for(int A : {a, k - a}) {
		for(int B = 0; B < n; ++B) {
			for(ll where : {(ll) B * k + b, (ll) (B + 1) * k - b}) {
				//~ int x = where % k;
				//~ x = min(x, k - x);
				//~ if(x != b) {
					//~ continue;
				//~ }
				//~ debug() << imie(A) imie(x);
				ll dist = abs(where - A);
				ll here = 0;
				if(dist == 0) {
					here = 1;
				}
				else {
					ll g = __gcd(dist, (ll) n * k);
					here = (ll) n * k / g;
				}
				small = min(small, here);
				big = max(big, here);
			}
		}
	}
	printf("%lld %lld\n", small, big);
}