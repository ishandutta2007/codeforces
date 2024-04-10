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

void test_case() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<pair<int,int>>> edges(3 * n + 1);
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].emplace_back(b, i);
		edges[b].emplace_back(a, i);
	}
	vector<bool> used(3 * n + 1);
	vector<int> chosen;
	for(int i = 1; i <= 3 * n; ++i) {
		for(pair<int,int> e : edges[i]) {
			int j = e.first;
			if(!used[i] && !used[j]) {
				chosen.push_back(e.second);
				used[i] = used[j] = true;
			}
		}
	}
	if((int) chosen.size() >= n) {
		puts("Matching");
		for(int i = 0; i < n; ++i) {
			printf("%d ", chosen[i]);
		}
		puts("");
	}
	else {
		puts("IndSet");
		int cnt = 0;
		for(int i = 1; i <= 3 * n && cnt < n; ++i) {
			if(!used[i]) {
				printf("%d ", i);
				++cnt;
			}
		}
		puts("");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}