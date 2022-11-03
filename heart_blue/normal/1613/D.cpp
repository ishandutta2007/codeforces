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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const LL mod = 998244353;
const int N = 5e5 + 20;
int a[N];
LL dp[N];
int cnt[N];
LL sum[N];
LL p2[N];
LL res[N];
void init()
{
	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = p2[i - 1] * 2 % mod;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		fill(dp, dp + n + 1, 0);
		fill(cnt, cnt + n + 1, 0);
		fill(sum, sum + n + 10, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			int x = a[i];
			if (x > 0)
			{
				res[i] = (dp[x - 1] + dp[x]) % mod;
			}
			else
			{
				res[i] = (dp[x] + 1) % mod;
			}
			dp[x] = (dp[x] + res[i]) % mod;
		}
		LL ans = 0;

		for (int i = n; i >= 1; i--)
		{
			ans += res[i] * (1 + sum[a[i] + 2]) % mod;
			int x = a[i];
			if (x >= 2) sum[x] = (sum[x] + p2[cnt[x] + cnt[x - 2]]) % mod;
			cnt[x]++;
		}
		ans += p2[cnt[1]] - 1;
		printf("%lld\n", ans % mod);
	}
	return 0;

}