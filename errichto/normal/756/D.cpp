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

const int mod = 1e9 + 7;
const int nax = 5005;
int dp[nax][nax];
char sl[nax];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", sl);
	for(int i = 0; i < nax; ++i)
		dp[i][0] = 1;
	dp[0][0] = 0;
	
	for(int i = 0; i < n; ++i) {
		int low = i;
		while(low >= 1 && sl[low-1] != sl[i])
			--low;
		for(int len = 1; len <= n; ++len)
			dp[i+1][len] = ((dp[i][len] + dp[i+1][len-1]) % mod - dp[low][len-1] + mod) % mod;
	}
	printf("%d\n", dp[n][n]);
}