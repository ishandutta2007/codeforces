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
const int N = 2e5 + 10;
//C(n+k-1,k-1)
LL dp[N];
LL ans[N];
LL powmod(LL a, LL b, LL mod = INF)
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
void init(int n, int k)
{
	int l = 1;
	int r = k - 1;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] * (r + 1) % INF * powmod(l, INF - 2) % INF;
		r++, l++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	if (k == 0)
	{
		while (n--)
		{
			int x;
			scanf("%d", &x);
			printf("%d ", x);
		}
		return 0;
	}
	init(n, k);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		for (int j = i; j <= n; j++)
		{
			ans[j] += dp[j - i] * x % INF;
		}
		printf("%lld ", ans[i] % INF);
	}
	return 0;
}