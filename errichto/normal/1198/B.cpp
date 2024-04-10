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
 
const int INF = 1e9 + 5;
 
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int q;
	scanf("%d", &q);
	vector<pair<int,int>> s;
	s.emplace_back(0, INF);
	vector<int> when(n);
	for(int nr = 1; nr <= q; ++nr) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int who, x;
			scanf("%d%d", &who, &x);
			--who;
			a[who] = x;
			when[who] = nr;
		}
		else {
			int x;
			scanf("%d", &x);
			while(s.back().second <= x) {
				s.pop_back();
			}
			s.emplace_back(nr, x);
		}
	}
	// reverse(s.begin(), s.end());
	s.emplace_back(q + 1, 0);
	for(int i = 0; i < n; ++i) {
		int z = lower_bound(s.begin(), s.end(), make_pair(when[i], INF + 1)) - s.begin();
		printf("%d ", max(a[i], s[z].second));
	}
	puts("");
}