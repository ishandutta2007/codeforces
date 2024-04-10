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

const int mod = 998244353;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> dp(n + 1);
	dp[0] = 1;
	int pref = 1;
	for(int j = 2; j <= n; ++j) {
		for(int k = j; k <= n; k += j) {
			dp[k]++;
		}
	}
	for(int i = 1; i <= n; ++i) {
		dp[i] = (dp[i] + pref) % mod;
		// dp[i] = pref;
		// for(int j = 2; j <= i; ++j) {
			// if(i % j == 0) {
				// dp[i]++;
			// }
		// }
		pref = (pref + dp[i]) % mod;
	}
	debug() << imie(dp);
	printf("%d\n", dp[n]);
}