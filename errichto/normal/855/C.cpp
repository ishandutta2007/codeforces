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

const int mod = 1e9 + 7;
const int nax = 1e5 + 5;
vector<int> w[nax];
long long dp[nax][13][3];
int colors, spec_k, allowed_max;
long long tmp[13][3];

int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if( b % 2) r = (long long) r * a % mod;
		a = (long long) a * a % mod;
		b /= 2;
	}
	return r;
}

int my_inv(int a) { return my_pow(a, mod - 2); }

void dfs(int a, int par) {
	dp[a][0][0] = spec_k - 1;
	dp[a][1][1] = 1;
	dp[a][0][2] = colors - spec_k;
	for(int b : w[a]) if(b != par) {
		dfs(b, a);
		for(int i = 0; i <= allowed_max; ++i)
			for(int j : {0,1,2})
				tmp[i][j] = 0;
		for(int i = 0; i <= allowed_max; ++i)
			for(int j = 0; i + j <= allowed_max; ++j) {
				tmp[i+j][0] += dp[a][i][0] * (dp[b][j][1] + dp[b][j][0] + dp[b][j][2]) % mod;
				tmp[i+j][1] += dp[a][i][1] * dp[b][j][0];
				tmp[i+j][2] += dp[a][i][2] * (dp[b][j][0] + dp[b][j][2]) % mod;
				tmp[i+j][0] %= mod;
				tmp[i+j][1] %= mod;
				tmp[i+j][2] %= mod;
			}
		for(int i = 0; i <= allowed_max; ++i)
			for(int j : {0,1,2})
				dp[a][i][j] = tmp[i][j];
	}
}

int main() {
	int n;
	scanf("%d%d", &n, &colors);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	scanf("%d%d", &spec_k, &allowed_max);
	dfs(1, -1);
	int answer = 0;
	for(int i = 0; i <= allowed_max; ++i)
		answer = (answer + (long long) dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) % mod;
	printf("%d\n", answer);
	//for(int i = 1; i <= n; ++i) printf("%lld\n", dp[i][0][2]);
}