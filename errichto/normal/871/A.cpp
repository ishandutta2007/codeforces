#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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


bool ok(int a) {
	for(int i = 2; i * i <= a; ++i)
		if(a % i == 0)
			return true;
	return false;
}

vector<int> they;

const int nax = 105;
int dp[nax];

int main() {
	for(int i = 2; i <= 30; ++i)
		if(ok(i))
			they.push_back(i);
	debug() << imie(they);
	
	for(int i = 1; i < nax; ++i) {
		if(ok(i)) dp[i] = 1;
		for(int x : they) if(i > x && dp[i-x] > 0)
			dp[i] = max(dp[i], dp[i-x] + 1);
	}
	
	int q;
	scanf("%d", &q);
	while(q--) {
		int n;
		scanf("%d", &n);
		if(n < nax) {
			if(dp[n] == 0) puts("-1");
			else printf("%d\n", dp[n]);
			continue;
		}
		int ans = -1;
		for(int i = 1; i < nax; ++i)
			if(n > i && dp[i] > 0 && (n - i) % 4 == 0)
				ans = max(dp[i] + (n - i) / 4, ans);
		printf("%d\n", ans);
	}
}