#include <bits/stdc++.h>

#define maxn 150005

using ll = long long;

int n,m,d,a[maxn];
ll b[maxn],t[maxn],dp[2][maxn];

namespace MQ {
	int Q[maxn],hd,tl,p,lastR;
	void reset(int x) { p = x; lastR = 0; hd = 1; tl = 0; }
	ll max() {
		if (hd > tl) return -1e18;
		return dp[p][Q[hd]];
	}
	void ins(int x) {
		while (hd <= tl && dp[p][Q[tl]] <= dp[p][x]) tl--;
		Q[++tl] = x;
	}
	void update(int L,int R) {
		while (hd <= tl && Q[hd] < L) hd ++;
		while (lastR < R) ins(++lastR);
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&d);
	for (int i = 1; i <= m; ++ i) 
		scanf("%d%lld%lld",&a[i],&b[i],&t[i]);
	t[0] = 1;
	for (int i = 1; i <= m; ++ i) {
		int x = i & 1; int y = x ^ 1;
		ll dt = t[i] - t[i-1];
		MQ::reset(y);
		for (int j = 1; j <= n; ++ j) {
			int L = std::max(1ll,j - (ll) dt * d);
			int R = std::min((ll) n,j + (ll) dt * d);
			MQ::update(L,R);
			dp[x][j] = MQ::max() - std::abs(a[i] - j) + b[i];
		}
	//	for (int j = 1; j <= n; ++ j) printf("%lld ",dp[x][j]); puts("");
	} ll ans = -1e18;
	for (int i = 1; i <= n; ++ i) ans = std::max(ans,dp[m&1][i]);
	printf("%lld",ans);
	return 0;
}