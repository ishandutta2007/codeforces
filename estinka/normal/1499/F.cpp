#include <iostream>
#include <string>
#include <set>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <queue>
typedef long long ll;
using namespace std;

const ll mod = 998244353;
const int maxn = 5128;
void upd(int& a, const int& b)
{
	a += b;
	if (a >= mod) a -= mod;
}
int mul(const int& a, const int& b)
{
	return (a * 1ll * b) % mod;
}
int n, k;
vector<vector<int> > dp(maxn, vector<int>(maxn, 0)), g(maxn);
vector<int> pfpar(maxn, 0), pfmy(maxn, 0), dptmp(maxn);
void dfs(int v, int p = -1)
{
	dp[v][0] = 1;
	for (int i : g[v])
	{
		if (i != p) dfs(i, v);
	}
	if (p == -1) return;
	for (int i = 0; i <= k; i++) pfpar[i] = pfmy[i] = 0;
	for (int i = 0; i <= k; i++)
	{
		if (i) pfpar[i] = pfpar[i - 1], pfmy[i] = pfmy[i - 1];
		upd(pfpar[i], dp[p][i]);
		upd(pfmy[i], dp[v][i]);
		dptmp[i] = dp[p][i];
		dp[p][i] = 0;
	}
	for (int mymax = 0; mymax < k; mymax++)
	{
		int pmax = min(mymax + 1, k - mymax - 1);
		upd(dp[p][mymax + 1], mul(pfpar[pmax], dp[v][mymax]));
	}
	for (int pmax = 2; pmax < k; pmax++)
	{
		int mymax = min(pmax - 2, k - pmax - 1);
		upd(dp[p][pmax], mul(dptmp[pmax], pfmy[mymax]));
	}
	for (int pmax = 0; pmax <= k; pmax++) upd(dp[p][pmax], mul(dptmp[pmax], pfmy[k]));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0, a, b; i < n - 1; i++) cin >> a >> b, g[--a].push_back(--b), g[b].push_back(a);
	dfs(0);
	int ans = 0;
	for (int i = 0; i <= k; i++) upd(ans, dp[0][i]);
	cout << ans << "\n";
	return 0;
}