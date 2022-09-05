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

const int nax = 1e5 + 5;
int low[nax], high[nax];
vector<int> edges[nax];

pair<long long, long long> dfs(int a, int parent) {
	long long one = 0, two = 0;
	for(int b : edges[a]) {
		if(b == parent) {
			continue;
		}
		pair<long long, long long> he = dfs(b, a);
		one += max(he.first + abs(low[a] - low[b]),
			he.second + abs(low[a] - high[b]));
		two += max(he.first + abs(high[a] - low[b]),
			he.second + abs(high[a] - high[b]));
	}
	return {one, two};
}

void test_case() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &low[i], &high[i]);
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	auto p = dfs(1, -1);
	printf("%lld\n", max(p.first, p.second));
	for(int i = 0; i <= n; ++i) {
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