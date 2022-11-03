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
const int N = 3e3 + 10;
pair<int, int> a[N];
LL dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + n + 1);
	dp[1] = a[1].second;
	for (int i = 2; i <= n; i++)
	{
		LL tot = 0;
		LL cnt = 0;
		dp[i] = INF * INF;
		for (int j = i - 1; j >= 1; j--)
		{
			dp[i] = min(dp[i], dp[j] + tot - cnt * a[j].first);
			cnt++;
			tot += a[j].first;
		}
		dp[i] += a[i].second;
	}
	LL ans = INF * INF;
	for (int i = 1; i <= n; i++)
	{
		LL sum = dp[i];
		for (int j = i + 1; j <= n; j++)
		{
			sum += a[j].first - a[i].first;
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}