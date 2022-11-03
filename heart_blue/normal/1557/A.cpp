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
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &sum[i]);
		}
		sort(sum + 1, sum + n + 1);
		for (int i = 1; i <= n; i++)
		{
			sum[i] += sum[i - 1];
		}
		double ans = -1e18;
		for (int i = 1; i < n; i++)
		{
			ans = max(ans, sum[i] * 1.0 / i + (sum[n] - sum[i]) * 1.0 / (n - i));
		}
		printf("%.15f\n", ans);
	}
	return 0;
}