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

const int nax = 200'005;
char s[nax];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	vector<vector<pair<int,int>>> intervals(n);  // (L, cost)
	for(int i = 0; i < n; ++i) {
		if(s[i] == '1') {
			int L = max(0, i - k);
			int R = min(n - 1, i + k);
			intervals[R].emplace_back(L, i + 1);
			debug() << imie(i) imie(L) imie(R);
		}
	}
	vector<long long> dp(n + 1);
	dp[0] = 0;
	int base = 1;
	while(base <= n + 1) base *= 2;
	vector<long long> tree(2 * base, LONG_LONG_MAX);
	for(int pos = base + 0; pos >= 1; pos /= 2) {
		tree[pos] = 0;
	}
	// dp[x] is best cost to cover everything before x
	for(int i = 0; i < n; ++i) {
		long long me = dp[i] + (i + 1);
		for(pair<int,int> p : intervals[i]) {
			int L = p.first;
			int cost = p.second;
			int left = base + L;
			int right = base + i;
			me = min({me, cost+tree[left], cost+tree[right]});
			while(left + 1 < right) {
				if(left % 2 == 0) me = min(me, cost+tree[left+1]);
				if(right % 2 == 1) me = min(me, cost+tree[right-1]);
				left /= 2;
				right /= 2;
			}
			// for(int j = L; j <= i; ++j) {
				// me = min(me, cost + dp[j]);
			// }
		}
		dp[i+1] = me;
		for(int pos = base + i+1; pos >= 1; pos /= 2) {
			tree[pos] = min(tree[pos], me);
		}
	}
	debug() << imie(dp);
	printf("%lld\n", dp[n]);
}