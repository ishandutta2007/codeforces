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

const int nax = 5e5 + 5;
vector<pair<int,int>> edges[nax];
int k;

// (saturated, available)
// (big, small)
pair<ll,ll> dfs(int a, int parent) {
	ll sure = 0;
	vector<ll> extra;
	for(pair<int,int> e : edges[a]) {
		int b = e.first, len = e.second;
		if(b == parent) {
			continue;
		}
		pair<ll,ll> p = dfs(b, a);
		sure += p.first;
		ll possible = p.second - p.first + len;
		if(possible > 0) {
			extra.push_back(possible);
		}
	}
	sort(extra.rbegin(), extra.rend());
	long long A = 0;
	for(int i = 0; i < min(k - 1, (int) extra.size()); ++i) {
		A += extra[i];
	}
	long long B = A;
	if((int) extra.size() >= k) {
		B += extra[k-1];
	}
	return make_pair(sure + B, sure + A);
}

void test_case() {
	int n;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edges[a].emplace_back(b, c);
		edges[b].emplace_back(a, c);
	}
	pair<ll,ll> p = dfs(1, -1);
	printf("%lld\n", max(p.first, p.second));
	for(int i =0 ; i <= n; ++i) {
		edges[i].clear();
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}