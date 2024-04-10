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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
map<int, int> mc;
int a[N], g[N], b[N];
int dp[N];
int sum[N];
map<int, int> mc2;
int getans(int x)
{
	if (mc2.count(x)) return mc2[x];
	int &ans = mc2[x];
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i) continue;
		int o = 1;
		if (mc.count(i)) o = -1;
		while (x%i == 0) ans += o, x /= i;
	}
	if (x > 1)
	{
		if (mc.count(x)) ans--;
		else ans++;
	}
	return ans;
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	g[0] = 0;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	while (m--)
	{
		int x;
		scanf("%d", &x);
		mc[x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		g[i] = gcd(g[i - 1], a[i]);
		sum[i] = getans(a[i]) + sum[i - 1];
		b[i] = getans(g[i]);
	}
	int ans = sum[n];
	for (int i = n; i > 0; i--)
	{
		dp[i] = (sum[n] - sum[i - 1]) - b[i];
		for (int j = i + 1; j <= n; j++)
		{
			dp[i] = max(dp[i], dp[j] + sum[j - 1] - sum[i - 1] - b[j] * (j - i - 1) - b[i]);
		}
		ans = max(ans, dp[i] + sum[i - 1] - (i - 1)*b[i]);
	}
	cout << ans << endl;
	return 0;
}