#include <bits/stdc++.h>
using namespace std;

string G[20];
vector <int> a;
vector <vector <int> > all;
long long val[400];
long long dp[1 << 18][18];
long long f[20][1 << 18];
long long tmp[1 << 18];
int cnt[1 << 18];

void dfs(int n, int len) {
	if (n == 0) {
		all.push_back(a);
		return ;
	}
	if (n < len) return ;
	dfs(n, len + 1);
	a.push_back(len);
	dfs(n - len, len);
	a.pop_back();
}

int main() {
	for (int i = 1; i < (1 << 18); i++) {
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> G[i];
	}
	dfs(n, 1);
	sort(all.begin(), all.end());
	for (int i = 0; i < n; i++) {
		dp[1 << i][i] = 1;
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int j = 0; j < n; j++) {
			if (!(mask >> j & 1)) continue;
			f[cnt[mask]][mask] += dp[mask][j];
			for (int k = 0; k < n; k++) {
				if (G[j][k] == '1' && !(mask >> k & 1)) dp[mask | 1 << k][k] += dp[mask][j];
			}
		}
	}
	for (int i = 1; i <= 18; i++) {
		for (int j = 0; j < 18; j++) {
			for (int mask = 0; mask < (1 << n); mask++) {
				if (mask >> j & 1) f[i][mask] += f[i][mask ^ 1 << j];
			}
		}
	}
	for (int i = 0; i < all.size(); i++) {
		for (int k = 0; k < (1 << n); k++) {
			tmp[k] = 1;
		}
		for (int j = 0; j < all[i].size(); j++) {
			int x = all[i][j];
			for (int k = 0; k < (1 << n); k++) {
				tmp[k] = tmp[k] * f[x][k];
			}
		}
		for (int j = 0; j < (1 << n); j++) {
			val[i] += tmp[j] * (n - cnt[j] & 1 ? -1 : 1);
		}
	}
	for (int i = 0; i < (1 << n - 1); i++) {
		int lst = -1;
		a.clear();
		for (int j = 0; j < n - 1; j++) {
			if (!(i >> j & 1)) a.push_back(j - lst), lst = j;
		}
		a.push_back(n - 1 - lst);
		sort(a.begin(), a.end());
		tmp[i] = val[lower_bound(all.begin(), all.end(), a) - all.begin()];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int mask = 0; mask < (1 << n - 1); mask++) {
			if (!(mask >> i & 1)) tmp[mask] -= tmp[mask ^ 1 << i];
		}
	}
	for (int i = 0; i < (1 << n - 1); i++) {
		printf("%I64d ", tmp[i]);
	}
	printf("\n");
	return 0;
}