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
const int N = 5e3 + 10;
int dp1[N][N];
int dp2[N][N];
int minv[N][N];
int a[N];
int ans[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n == 1)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = a[n + 1] = -INF;
	if (n == 2)
	{
		printf("%d\n", a[1] == a[2] ? 1 : 0);
		return 0;
	}
	MEM(dp1, 0x3f);
	MEM(dp2, 0x3f);
	MEM(minv, 0x3f);
	MEM(ans, 0x3f);
	dp1[1][1] = dp2[1][1] = max(a[2] - a[1] + 1, 0);
	dp1[2][1] = max(max(a[3], a[1]) - a[2] + 1, 0);
	dp2[2][1] = max(0, a[3] - a[2] + 1) + max(0, abs(a[1] - a[2]) + 1);
	minv[1][1] = min(dp1[1][1], dp2[1][1]);
	minv[2][1] = min(dp2[2][1], dp1[2][1]);
	for (int i = 0; i < N; i++) minv[i][0] = dp1[i][0] = dp2[i][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		//dp1[i][1] = max(max(a[i + 1], a[i - 1]) - a[i] + 1, 0);
		dp2[i][1] = max(0, a[i + 1] - a[i] + 1) + max(0, a[i - 1] - a[i] + 1);
		minv[i][1] = min(dp1[i][1], dp2[i][1]);
		minv[i][1] = min(minv[i][1], minv[i - 1][1]);
	}
	for (int i = 3; i <= n; i++)
	{
		for (int j = 2; j <= (i + 1) / 2; j++)
		{
			//dp1[i][j] = min(dp1[i][j], minv[i - 3][j - 1] + max(max(a[i + 1], a[i - 1]) - a[i] + 1, 0));
			//dp1[i][j] = min(dp1[i][j], dp1[i - 2][j - 1] + max(max(a[i + 1], a[i - 1]) - a[i] + 1, 0));
			//dp1[i][j] = min(dp1[i][j], dp2[i - 2][j - 1] + max(0, max(a[i + 1], min(a[i - 2] - 1, a[i - 1])) - a[i] + 1));
			dp2[i][j] = min(dp2[i][j], minv[i - 3][j - 1] + max(0, a[i - 1] - a[i] + 1) + max(0, a[i + 1] - a[i] + 1));
			//dp2[i][j] = min(dp2[i][j], dp1[i - 2][j - 1] + max(0, a[i - 1] - a[i] + 1) + max(0, a[i + 1] - a[i] + 1));
			dp2[i][j] = min(dp2[i][j], dp2[i - 2][j - 1] + max(0, min(a[i - 1], a[i - 2] - 1) - a[i] + 1) + max(0, a[i + 1] - a[i] + 1));
			minv[i][j] = min(minv[i][j], dp2[i][j]);
			minv[i][j] = min(minv[i][j], minv[i - 1][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans[j] = min(ans[j], minv[i][j]);
		}
	}
	for (int i = 1; i <= (n + 1) / 2; i++) printf("%d ", ans[i]);
	return 0;
}