#pragma GCC optimize ("Ofast")
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
	ll k, d, t;
	cin >> k >> d >> t;
	if(k % d)
		d = d * (k / d + 1);
	debug() << imie(d);
	if(d <= k) {
		printf("%lld\n", t);
		return 0;
	}
	t *= 2;
	ll once = 2 * k + (d - k);
	ll wholes = t / once;
	double answer = wholes * d;
	debug() << imie(once) imie(wholes);
	ll rem = t % once;
	if(rem <= 2 * k) answer += rem / 2.;
	else answer += k + (rem - 2 * k);
	printf("%.10lf\n", answer);
}