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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
int a[N];
int d[N];
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l, k;
	scanf("%d%d%d", &n, &l, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	d[n + 1] = l;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	MEM(dp, 0x3f);
	MEM(dp[1], 0);
	n++;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			for (int t = 0; t < j; t++)
			{
				dp[i][i - j - 1 + t] = min(dp[i][i - j - 1 + t], 
					dp[j][t] + a[j]*(d[i]-d[j]));
			}
		}
		for (int j = 1; j < i; j++)
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
	}
	printf("%d\n", dp[n][k]);

	return 0;
}