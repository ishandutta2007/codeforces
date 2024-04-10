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

int query(int x) {
	printf("%d\n", x);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	if(r == 0) exit(0);
	return r;
}

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	vector<int> cor(n);
	for(int i = 0; i < n; ++i) {
		int r = query(1);
		if(r == 1) cor[i] = true;
		else cor[i] = false;
	}
	int low = 1, high = m;
	while((int) cor.size() < 35) {
		auto tmp = cor;
		for(auto x : tmp) cor.push_back(x);
	}
	for(bool xo : cor) {
		int mid = (low + high) / 2;
		int r = query(mid);
		if(!xo) r *= -1;
		if(r == 1) low = mid + 1;
		else high = mid - 1;
	}
	assert(false);
}