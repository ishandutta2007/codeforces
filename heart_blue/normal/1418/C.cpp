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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
int a[N];
int dp[N][2];
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		memset(dp, 0x3f, sizeof(dp[0]) * (n + 1));
		dp[1][1] = a[1];
		dp[2][1] = a[1] + a[2];
		dp[2][0] = a[1];
		for (int i = 3; i <= n; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
			dp[i][1] = min(dp[i - 1][0] + a[i], dp[i - 2][0] + a[i] + a[i - 1]);
		}
		printf("%d\n", min(dp[n][0], dp[n][1]));
	}
	return 0;
}