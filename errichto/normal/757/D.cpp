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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

const int N = 76;
char sl[N];
const int mod = 1e9 + 7;
int dp[N][1 << 20];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", sl);
	for(int i = 0; i < n; ++i)
		dp[i][0] = 1;
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j) {
			int x = 0;
			for(int k = i; k <= j; ++k) {
				x *= 2;
				if(sl[k] == '1') ++x;
				if(x >= 25) break;
			}
			--x;
			if(x == -1 || x >= 20) continue;
			debug() << imie(i) << imie(j) << imie(x);
			for(int mask = 0; mask < (1 << 20); ++mask) {
				int & ple = dp[j+1][mask | (1 << x)];
				if((ple += dp[i][mask]) >= mod)
					ple -= mod;
			}
		}
	debug() << imie(dp[2][2]);
	debug() << "dupsko";
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int k = 1; k < 25; ++k) {
			int mask = (1 << k) - 1;
			assert(mask >= 0);
			if(mask < (1 << 20) && dp[i][mask]) {
				debug() << imie(i) << imie(mask) << imie(dp[i][mask]);
				if((ans += dp[i][mask]) >= mod)
					ans -= mod;
			}
		}
	printf("%d\n", ans);
}