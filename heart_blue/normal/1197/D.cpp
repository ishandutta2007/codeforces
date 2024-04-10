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
LL sum[N];
LL dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &sum[i]);
		sum[i] += sum[i - 1];
	}
	set<pair<LL, int>> sp;
	int ptr = 0;
	LL ans = 0;
	for (int i = 0; i <= n; i++)
	{
		sp.erase(make_pair(sum[i], i));
		ptr = max(ptr, i + 1);
		if (i >= m)
		{
			dp[i] = max(dp[i], dp[i - m] + sum[i] - sum[i - m] - k);
		}
		ans = max(ans, dp[i]);
		while (ptr <= n && ptr <= i + m)
		{
			sp.emplace(sum[ptr], ptr);
			ptr++;
		}
		if (!sp.empty())
			ans = max(ans, dp[i] + sp.rbegin()->first - sum[i] - k);
	}
	printf("%lld\n", ans);
	return 0;

}