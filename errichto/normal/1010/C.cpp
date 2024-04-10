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
	int n, mod;
	scanf("%d%d", &n, &mod);
	vector<int> they;
	int small = mod;
	while(n--) {
		int x;
		scanf("%d", &x);
		small = __gcd(small, x);
	}
	//~ sort(they.begin(), they.end());
	//~ they.resize( unique(they.begin(), they.end()) - they.begin() );
	//~ int small = they[0];
	//~ for(int i = 0; i < (int) they.size(); ++i)
		//~ for(int j = i + 1; j < (int) they.size(); ++j)
			//~ small = min(small, __gcd(they[i], they[j]));
	//~ debug() << imie(small);
	printf("%d\n", mod / small);
	for(int i = 0; i < mod / small; ++i)
		printf("%d ", small * i);
	puts("");
}