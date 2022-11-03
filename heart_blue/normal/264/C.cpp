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
const int N = 1e5 + 10;

int v[N];
int c[N];
LL dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	while (q--)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		int k1 = 0, k2 = 0;
		LL ans = 0;
		MEM(dp, 0xa0);
		for (int i = 1; i <= n; i++)
		{
			int o = c[i];
			LL t1 = max(dp[o] + a * v[i], b*v[i]);
			LL t2 = (k1 != o ? dp[k1] : dp[k2]) + b * v[i];
			dp[o] = max(dp[o], max(t1, t2));
			ans = max(ans, dp[o]);
			if (o == k1 || o == k2)
			{
				if (dp[k1] < dp[k2]) swap(k1, k2);
			}
			else
			{
				if (dp[k2] < dp[o]) swap(k2,o);
				if (dp[k1] < dp[k2]) swap(k1, k2);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}