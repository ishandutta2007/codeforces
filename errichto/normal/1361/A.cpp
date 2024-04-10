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



int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> edges(n + 1);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int> topic(n + 1);
	vector<pair<int,int>> order;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &topic[i]);
		order.emplace_back(topic[i], i);
	}
	sort(order.begin(), order.end());
	vector<bool> vis(n + 1);
	for(pair<int,int> p : order) {
		int a = p.second;
		set<int> forbidden;
		for(int b : edges[a]) {
			if(vis[b]) {
				forbidden.insert(topic[b]);
			}
		}
		int got = 1;
		while(forbidden.count(got)) {
			got++;
		}
		if(got != topic[a]) {
			puts("-1");
			return 0;
		}
		vis[a] = true;
	}
	for(pair<int,int> p : order) {
		printf("%d ", p.second);
	}
	puts("");
	// multiset<pair<int,int>> s;
	// for(int i = 1; i <= n; ++i) {
		// s.insert({
	// while(!
}