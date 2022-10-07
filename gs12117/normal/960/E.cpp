#include<cstdio>
#include<vector>
int n;
int v[200100];
std::vector<int> el[200100];
int chk[200100];
int dp[200100][2];
const int mod = 1000000007;
long long int ans;
void dfs(int x) {
	if (chk[x] == 1)return;
	chk[x] = 1;
	dp[x][0] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] != 1) {
			dfs(y);
			dp[x][0] += dp[y][1];
			dp[x][1] += dp[y][0];
		}
	}
}
void sdfs(int x, int enn, int onn) {
	if (chk[x] == 2)return;
	chk[x] = 2;
	ans += ((long long int)enn)*v[x];
	ans %= mod;
	enn++;
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] != 2) {
			ans += ((long long int)enn)*dp[y][1] % mod*v[x];
			ans %= mod;
			enn += dp[y][1];
			ans -= ((long long int)onn)*dp[y][0] % mod*v[x];
			ans %= mod;
			onn += dp[y][0];
		}
	}
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] != 2) {
			sdfs(y, onn - dp[y][0], enn - dp[y][1]);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		el[x].push_back(y);
		el[y].push_back(x);
	}
	dfs(1);
	sdfs(1, 0, 0);
	ans *= 2;
	ans %= mod;
	for (int i = 1; i <= n; i++) {
		ans += v[i];
		ans %= mod;
	}
	ans += mod;
	ans %= mod;
	printf("%lld", ans);
	return 0;
}