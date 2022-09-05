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

vector<pair<int,int>> read(int n) {
	vector<pair<int,int>> w(n);
	for(pair<int,int> & p : w) scanf("%d%d", &p.first, &p.second);
	return w;
}

int share(pair<int,int> a, pair<int,int> b) {
	int cnt = 0;
	for(int x : {a.first, a.second})
		for(int y : {b.first, b.second})
			cnt += x == y;
	if(cnt != 1) return 0;
	for(int x : {a.first, a.second})
		for(int y : {b.first, b.second})
			if(x == y)
				return x;
	assert(false);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	auto a = read(n);
	auto b = read(m);
	set<int> maybe;
	for(auto p : a) for(auto q : b)
		if(share(p, q))
			maybe.insert(share(p, q));
	assert(!maybe.empty());
	if((int) maybe.size() == 1) {
		printf("%d\n", *maybe.begin());
		return 0;
	}
	for(int rep = 0; rep < 2; ++rep) {
		for(pair<int,int> p : a) {
			maybe.clear();
			for(pair<int,int> q : b)
				if(share(p, q))
					maybe.insert(share(p, q));
			if((int) maybe.size() >= 2) {
				puts("-1");
				return 0;
			}
		}
		swap(a, b);
	}
	puts("0");
}