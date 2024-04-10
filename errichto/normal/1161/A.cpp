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
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(k);
	vector<pair<int,int>> answer;
	set<int> vis;
	for(int i = 0; i < k; ++i) {
		scanf("%d", &a[i]);
		vis.insert(a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		if(!vis.count(i)) {
			answer.push_back({i, i});
			if(i != 1) {
				answer.push_back({i - 1, i});
				answer.push_back({i, i - 1});
			}
			if(i != n) {
				answer.push_back({i, i + 1});
				answer.push_back({i + 1, i});
			}
		}
		//~ if(!vis.count(i) && !vis.count(i+1) && i != n) {
			//~ answer.insert({i, i + 1});
			//~ answer.insert({i + 1, i});
		//~ }
	}
	vector<int> cnt(n + 1);
	for(int x : a) {
		++cnt[x];
	}
	vector<bool> done(n + 1);
	for(int x : a) {
		done[x] = true;
		--cnt[x];
		for(int y : {x - 1, x + 1}) {
			if(y != 0 && y != n + 1) {
				if(cnt[x] == 0 && !done[y]) {
					answer.push_back({y, x});
				}
			}
		}
	}
	sort(answer.begin(), answer.end());
	answer.resize( unique(answer.begin(), answer.end()) - answer.begin() );
	printf("%d\n", (int) answer.size());
}