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
	int n, q, c;
	scanf("%d%d%d", &n, &q, &c);
	vector<ll> t(n);
	vector<bool> big(n);
	int need = 0;
	auto f = [&](int i) {
		return big[i] && (i == 0 || !big[i-1]);
	};
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &t[i]);
		big[i] = t[i] > c;
		need += f(i);
	}
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == 0) {
			printf("%d\n", need);
		}
		else {
			int i, x;
			scanf("%d%d", &i, &x);
			--i;
			need -= f(i);
			if(i != n - 1) {
				need -= f(i+1);
			}
			t[i] += x;
			big[i] = t[i] > c;
			need += f(i);
			if(i != n - 1) {
				need += f(i+1);
			}
		}
	}
}