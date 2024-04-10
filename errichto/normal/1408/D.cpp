#include <bits/stdc++.h>
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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }



int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int,int>> robber(n);
	vector<pair<int,int>> light(m);
	for(pair<int,int>& p : robber) {
		scanf("%d%d", &p.first, &p.second);
	}
	for(pair<int,int>& p : light) {
		scanf("%d%d", &p.first, &p.second);
	}
	vector<pair<int,int>> all;
	for(pair<int,int> p : robber) {
		for(pair<int,int> q : light) {
			if(p.first <= q.first && p.second <= q.second) {
				all.emplace_back(q.first - p.first, q.second - p.second);
			}
		}
	}
	sort(all.rbegin(), all.rend());
	if(all.empty()) {
		puts("0");
		return 0;
	}
	int answer = INT_MAX;
	int big = -1;
	for(pair<int,int> p : all) {
		answer = min(answer, p.first + 1 + big + 1);
		big = max(big, p.second);
	}
	answer = min(answer, big + 1);
	printf("%d\n", answer);
}