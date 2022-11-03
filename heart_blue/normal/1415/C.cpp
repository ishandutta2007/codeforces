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
char str[N];
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, p, k;
		scanf("%d%d%d", &n, &p, &k);
		int ans = 2 * INF;
		scanf("%s", str + 1);
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = n; i >= p; i--)
		{
			dp[i] = str[i] == '0';
			if (i + k <= n) dp[i] += dp[i + k];
			ans = min(ans, dp[i] * x + (i - p) * y);
		}
		printf("%d\n", ans);
	}
	return 0;
}