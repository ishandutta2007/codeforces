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
const int N = 3e5 + 10;
int dp[N][6];
int pre[N][6];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fill(dp[1], dp[1] + 6, 1);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (i == 1) continue;
		for (int j = 1; j <= 5; j++)
		{
			if (dp[i - 1][j] == 0) continue;
			for (int k = 1; k <= 5; k++)
			{
				if (a[i - 1] < a[i] && j < k)
				{
					dp[i][k] = 1;
					pre[i][k] = j;
				}
				if (a[i - 1] > a[i] && j > k)
				{
					dp[i][k] = 1;
					pre[i][k] = j;
				}
				if (a[i - 1] == a[i] && j != k)
				{
					dp[i][k] = 1;
					pre[i][k] = j;
				}
			}
		}
	}
	int o = 0;
	for (int i = 1; i <= 5; i++)
	{
		if (dp[n][i])
			o = i;
	}
	if (o == 0)
	{
		puts("-1");
		return 0;
	}
	vector<int> ans;
	for (int i = n; i > 0; i--)
	{
		ans.push_back(o);
		o = pre[i][o];
	}
	reverse(ans.begin(), ans.end());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}