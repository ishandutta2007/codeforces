#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
int cnt[20000010];
long long dp[20000010];
int vis[20000010], minp[20000010], prime[20000010], tot;
vector <pii> fac;

void PreCalc(int N) {
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[tot++] = i, minp[i] = i;
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1, minp[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
}

void dfs(int now, int val) {
	if (now == fac.size()) {
		cnt[val]++;
		return ;
	}
	for (int i = 0; i <= fac[now].se; i++) {
		dfs(now + 1, val);
		if (i == fac[now].se) break;
		val *= fac[now].fi;
	}
}

void Calc(int x) {
	fac.clear();
	while (x > 1) {
		int p = minp[x];
		if (fac.size() && fac.back().fi == p) fac.back().se++;
		else fac.push_back(mp(p, 1));
		x /= p;
	}
	dfs(0, 1);
}

int main() {
	int N = 20000000; PreCalc(N);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		Calc(x);
	}
	long long *END = dp + N;
	for (int i = N; i >= 1; i--) {
		if (!cnt[i]) continue;
		long long &res = dp[i] = 0;
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			res = max(res, dp[i * prime[j]] - 1ll * cnt[i * prime[j]] * i);
		}
		dp[i] += 1ll * cnt[i] * i;
	}
	printf("%lld\n", dp[1]);
	return 0;
}