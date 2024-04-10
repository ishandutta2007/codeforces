#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

int main() {
	long long n, l, r;
	cin >> n >> l >> r;
	if(n == 0) {
		puts("0");
		return 0;
	}
	if(n == 1) {
		puts("1");
		return 0;
	}
	ll ple = 1;
	while(n >= ple) ple *= 2;
	ll half = ple / 2 - 1;
	ll ans = 0;
	for(ll i = l; i <= r; ++i) {
		ll x = i;
		ll memo = half;
		for(int j = 0; true; ++j) {
			if(x == half + 1) {
				ans += bool(n & (1LL << j));
				break;
			}
			assert(half > 0);
			if(x > half) x -= half + 1;
			half /= 2;
		}
		half = memo;
	}
	cout << ans << "\n";
}