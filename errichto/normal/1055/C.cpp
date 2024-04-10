#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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



int main() {
	ll la, ra, ta;
	ll lb, rb, tb;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	ll g = __gcd(ta, tb);
	if(la > lb) {
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}
	ll diff = lb - la;
	la += diff / g * g;
	ra += diff / g * g;
	debug() << imie(la) imie(ra) imie(ta) imie(g);
	debug() << imie(lb) imie(rb) imie(tb);
	debug();
	ll one = min(ra, rb) - max(la, lb) + 1;
	la += g;
	ra += g;
	debug() << imie(la) imie(ra) imie(ta) imie(g);
	debug() << imie(lb) imie(rb) imie(tb);
	debug();
	ll two = min(ra, rb) - max(la, lb) + 1;
	printf("%lld\n", max({0LL, one, two}));
}