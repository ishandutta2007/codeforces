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
void maxi(ll & a, ll b) { a = max(a, b); }

int main() {
	ll n, a, b, c;
	scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
	vector<ll> t(n), suf_min(n), suf_max(n);
	for(ll & x : t) scanf("%lld", &x);
	suf_min.back() = suf_max.back() = t.back();
	for(int i = n - 2; i >= 0; --i) {
		suf_min[i] = min(suf_min[i+1], t[i]);
		suf_max[i] = max(suf_max[i+1], t[i]);
	}
	ll answer = t[0] * (a + b + c);
	ll small = t[0], big = t[0];
	for(int i = 0; i < n; ++i) {
		small = min(small, t[i]);
		big = max(big, t[i]);
		maxi(answer, max(a * small, a * big) + b * t[i] + max(c * suf_min[i], c * suf_max[i]));
	}
	printf("%lld\n", answer);
}