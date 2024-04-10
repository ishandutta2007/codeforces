#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

using ll = long long;

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> in(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &in[i]);
	}
	int at_most_total = n / 2;
	vector<int> v;
	for(int i = 0; i < n; ++i) {
		int cnt = 1;
		while(i + 1 < n && in[i] == in[i+1]) {
			++i;
			++cnt;
		}
		v.push_back(cnt);
	}
	n = v.size();
	vector<int> pref = v;
	for(int i = 1; i < n; ++i) {
		pref[i] += pref[i-1];
	}
	vector<int> best{0, 0, 0, 0};
	for(int last_gold = 0; last_gold < n; ++last_gold) {
		int gold = pref[last_gold];
		int i = upper_bound(pref.begin(), pref.end(), 2 * gold) - pref.begin();
		if(i == n) {
			break;
		}
		int silver = pref[i] - gold;
		i = upper_bound(pref.begin(), pref.end(), at_most_total) - pref.begin() - 1;
		if(i == -1) {
			continue;
		}
		int bronze = pref[i] - gold - silver;
		if(bronze <= gold) {
			continue;
		}
		int sum = gold + silver + bronze;
		if(sum <= at_most_total) {
			best = max(best, vector<int>{sum, gold, silver, bronze});
		}
	}
	printf("%d %d %d\n", best[1], best[2], best[3]);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}