#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef unsigned long long ull;

const int P1 = 23333, P2 = 3232323;
const int mod = 1000000007;

char s[100010], t[100010];
int dp[100010][40];
pair <ull, ull> hs[100010], ht[100010];
pair <ull, ull> pw[100010];

pair <ull, ull> get_h(int l, int r, pair <ull, ull> *h){
	return mp((h[r].fi - h[l - 1].fi * pw[r - l + 1].fi % mod + mod) % mod, 
			(h[r].se - h[l - 1].se * pw[r - l + 1].se % mod + mod) % mod);
}

int main(){
	pw[0].fi = pw[0].se = 1;
	for (int i = 1; i <= 100000; i++){
		pw[i].fi = pw[i - 1].fi * P1 % mod;
		pw[i].se = pw[i - 1].se * P2 % mod;
	}
	int n, m, k;
	scanf("%d%s%d%s", &n, s + 1, &m, t + 1);
	scanf("%d", &k);
	for (int i = 1; i <= n; i++){
		hs[i].fi = (hs[i - 1].fi * P1 + s[i]) % mod;
		hs[i].se = (hs[i - 1].se * P2 + s[i]) % mod;
	}
	for (int i = 1; i <= m; i++){
		ht[i].fi = (ht[i - 1].fi * P1 + t[i]) % mod;
		ht[i].se = (ht[i - 1].se * P2 + t[i]) % mod;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++){
		for (int t = 0; t <= k; t++){
			if (dp[i][t] == -1) continue;
			dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
			int j = dp[i][t];
			int l = 0, r = min(m - j, n - i);
			while (l < r){
				int mid = l + r + 1 >> 1;
				if (get_h(i + 1, i + mid, hs) == get_h(j + 1, j + mid, ht)) l = mid;
				else r = mid - 1;
			}
			dp[i + l][t + 1] = max(dp[i + l][t + 1], dp[i][t] + l);
		}
	}
	for (int j = 0; j <= k; j++){
		if (dp[n][j] == m){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}