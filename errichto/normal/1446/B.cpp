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

const int nax = 5005;
int dp[nax][nax];

int main() {
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = n - 1; i >= 0; --i) {
		for(int j = m - 1; j >= 0; --j) {
			dp[i][j] = max(dp[i+1][j], dp[i][j+1]) - 1;
			dp[i][j] = max(0, dp[i][j]);
			if(a[i] == b[j]) {
				dp[i][j] = 2 + dp[i+1][j+1];
			}
			ans = max(ans, dp[i][j]);
			if(i == j + 1) debug() << imie(i) imie(dp[i][j]);
		}
	}
	printf("%d\n", ans);
}