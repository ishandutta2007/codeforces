#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
LL dp[N][2];
int depth[N];
vector<int> v[N];
int col[N];
int fa[N];
LL ans = 1;
const LL mod = 998244353;
void dfs(int x, int p = 0)
{
	depth[x] = depth[p] + 1;
	fa[x] = p;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
LL powmod(LL a, LL b, LL mod = ::mod)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
void getans(int x, int p = 0)
{
	dp[x][col[x] != 0] = 1;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		getans(y, x);
		if (col[x])
		{
			dp[x][1] = dp[x][1] * (dp[y][0] + dp[y][1]) % mod;
		}
		else
		{
			dp[x][0] = dp[x][0] * (dp[y][0] + dp[y][1]) % mod;
			dp[x][1] = (dp[x][1] + dp[y][1] * powmod(dp[y][0] + dp[y][1], mod - 2)) % mod;
		}
	}
	if (!col[x]) dp[x][1] = 1LL * dp[x][1] * dp[x][0] % mod;
}
vector<int> c[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> col[i];
		c[col[i]].push_back(i);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= k; i++)
	{
		set<pair<int, int>> pq;
		for (auto& x : c[i])
		{
			pq.emplace(-depth[x], x);
		}
		while (pq.size() > 1)
		{
			int x = pq.begin()->second;
			pq.erase(pq.begin());
			if (col[x] == 0) col[x] = i;
			if (col[x] != i) puts("0"), exit(0);
			pq.emplace(-depth[x] + 1, fa[x]);
		}
		int x = pq.begin()->second;
		if (col[x] == 0) col[x] = i;
		if (col[x] != i) puts("0"), exit(0);
	}
	getans(c[1].front());
	cout << dp[c[1].front()][1] << endl;
	return 0;
}