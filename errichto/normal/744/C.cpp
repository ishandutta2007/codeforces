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

void maxi(int & a, int b) {
	a = max(a, b);
}

const int nax = 16;
char type[nax];
int r[nax], b[nax];

const int inf = 1e9 + 5;
int dp[1<<nax][nax*nax+1];
int R[1<<nax], B[1<<nax];
int cntR[1<<nax], cntB[1<<nax];


int main() {
	int n;
	scanf("%d\n", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%c %d %d\n", &type[i], &r[i], &b[i]);
	}
	/*for(int mask = 0; mask < (1 << n); ++mask)
		for(int i = 0; i < n; ++i)
			if(mask & (1 << i)) {
				R[mask] += r[i];
				B[mask] += b[i];
			}*/
	for(int mask = 0; mask < (1 << n); ++mask)
		for(int i = 0; i < n; ++i)
			if(mask & (1 << i)) {
				if(type[i] == 'R') ++cntR[mask];
				else ++cntB[mask];
			}
	for(int i = 0; i < (1 << n); ++i)
		for(int j = 0; j <= n * n; ++j)
			dp[i][j] = -inf;
	dp[0][0] = 0;
	for(int mask = 0; mask < (1 << n) - 1; ++mask)
		for(int r_already = 0; r_already <= n * n; ++r_already) {
			int c_already = dp[mask][r_already];
			if(c_already < 0) continue;
			for(int i = 0; i < n; ++i) if(!(mask & (1 << i))) {
				maxi(dp[mask | (1 << i)][r_already + min(cntR[mask], r[i])],
					c_already + min(cntB[mask], b[i]));
			}
		}
	int ans = inf;
	int r_total = 0, b_total = 0;
	for(int i = 0; i < n; ++i) {
		r_total += r[i];
		b_total += b[i];
	}
	for(int r_already = 0; r_already <= n * n; ++r_already) {
		int c_already = dp[(1<<n)-1][r_already];
		if(c_already < 0) continue;
		ans = min(ans, n + max(r_total - r_already, b_total - c_already));
	}
	printf("%d\n", ans);
}