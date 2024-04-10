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

using ll = long long;



int main() {
	long long len;
	int m;
	long long block;
	scanf("%lld%d%lld", &len, &m, &block);
	vector<ll> they(m);
	for(int i = 0; i < m; ++i) {
		scanf("%lld", &they[i]);
	}
	ll skipped = 0;
	int answer = 0;
	for(int i = 0; i < m; ++i) {
		#warning speed-up!
		ll diff = they[i] - skipped;
		ll times = max(0LL, diff) / block - 3;
		times = max(0LL, times);
		skipped += times * block;
		while(skipped + block < they[i]) {
			skipped += block;
		}
		int cnt = 1;
		while(i + 1 < m && they[i+1] <= skipped + block) {
			++i;
			++cnt;
		}
		++answer;
		skipped += cnt;
	}
	printf("%d\n", answer);
	
}