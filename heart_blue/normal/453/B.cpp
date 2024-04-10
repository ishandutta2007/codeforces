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
const int N = 60;
int a[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
int b[N];
const int k = 17;
int dp[101][1 << k];
int pre[101][1<<k];
int ans[101];
void init()
{
	for (int i = 0; i < k; i++)
	{
		for (int j = a[i]; j < N; j += a[i]) b[j] |= 1 << i;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	MEM(dp, 0x3f);
	dp[0][0] = 0;
	int n;
	cin >> n;
	int tot = 1 << k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < tot; j++)
		{
			for (int o = 1; o < N; o++)
			{
				if (j&b[o]) continue;
				if (dp[i][j | b[o]] > dp[i - 1][j] + abs(x - o))
				{
					dp[i][j | b[o]] = dp[i - 1][j] + abs(x - o);
					pre[i][j | b[o]] = o;
				}
			}
		}
	}
	int key = 0;
	for (int i = 0; i < tot; i++)
	{
		if (dp[n][i] < dp[n][key]) key = i;
	}
	//cout << dp[n][key] << endl;
	for (int i = n; i > 0; i--)
	{
		ans[i] = pre[i][key];
		key ^= b[pre[i][key]];
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

	return 0;
}