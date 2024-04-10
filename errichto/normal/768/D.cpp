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

typedef double ld;
const int nax = 1005;
ld dp[nax];
ld p_win[nax];
int ans[nax];

int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 0; i <= n; ++i)
		p_win[i] = (ld) (n - i) / n;
	dp[0] = 1;
	int next_to_do = 1;
	for(int day = 0; next_to_do < nax; ++day) {
		debug() << range(dp, dp + n + 1);
		for(int already = n - 1; already >= 0; --already) if(dp[already] > 1e-30) {
			ld tmp = p_win[already] * dp[already];
			dp[already+1] += tmp;
			dp[already] -= tmp;
		}
		while(next_to_do < nax && dp[n] > (next_to_do - 1e-7) / 2000)
			ans[next_to_do++] = day + 1;
	}
	while(q--) {
		int x;
		cin >> x;
		cout << ans[x] << "\n";
	}
}