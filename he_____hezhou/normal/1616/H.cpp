#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, x;
int a[150010];
int son[150010 * 30][2], sze[150010 * 30];
int cnt, rt;
void add(int &cur, int a, int dep) {
	if (cur == 0) cur = ++cnt;
	sze[cur]++;
	if (dep == -1) return;
	int nxt = (a >> dep) & 1;
	add(son[cur][nxt], a, dep - 1);
}
int power(int a, int b) {
	long long res = a, ans = 1;
	for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
	return ans;
}
int dfs(int a, int b, int dep) {
	if (a == 0 || b == 0) return power(2, sze[a] + sze[b]);
	if (dep == -1) return power(2, a == b ? sze[a] : sze[a] + sze[b]);
	if (a == b) {
		if ((x >> dep) & 1) {
			int ans = dfs(son[a][0], son[b][1], dep - 1);
			return ans;
		}
		else {
			int ans = dfs(son[a][0], son[b][0], dep - 1) + dfs(son[a][1], son[b][1], dep - 1) - 1;
			if (ans > mod) ans -= mod;
			if (ans < 0) ans += mod;
			return ans;
		}
	}
	else {
		if ((x >> dep) & 1) {
			int ans = 1ll * dfs(son[a][0], son[b][1], dep - 1) * dfs(son[a][1], son[b][0], dep - 1) % mod;
			return ans;
		}
		else {
			long long ans = dfs(son[a][0], son[b][0], dep - 1) + dfs(son[a][1], son[b][1], dep - 1) - 1;
			ans += mod;
			ans += 1ll * (power(2, sze[son[a][0]]) - 1) * (power(2, sze[son[a][1]]) - 1);
			ans += 1ll * (power(2, sze[son[b][0]]) - 1) * (power(2, sze[son[b][1]]) - 1);
			return ans % mod;
		}
	}
}
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		add(rt, a[i], 29);
	}
	cout << (dfs(rt, rt, 29) + mod - 1) % mod << endl;
}