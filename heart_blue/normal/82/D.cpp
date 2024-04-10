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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int a[N];
int dp[N][N];
pair<int, int> pre[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	MEM(dp, 0x3f);
	int inf = dp[1][1];
	dp[1][1] = 0;
	for (int i = 1; i + 2 <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// j i+1 i+2
			if (dp[i + 2][i + 2] > dp[i][j] + max(a[j], a[i + 1]))
			{
				dp[i + 2][i + 2] = dp[i][j] + max(a[j], a[i + 1]);
				pre[i + 2][i + 2] = make_pair(i, j);
			}
			if (dp[i + 2][i + 1] > dp[i][j] + max(a[j], a[i + 2]))
			{
				dp[i + 2][i + 1] = dp[i][j] + max(a[j], a[i + 2]);
				pre[i + 2][i + 1] = make_pair(i, j);
			}
			if (dp[i + 2][j] > dp[i][j] + max(a[i + 1], a[i + 2]))
			{
				dp[i + 2][j] = dp[i][j] + max(a[i + 1], a[i + 2]);
				pre[i + 2][j] = make_pair(i, j);
			}
		}
	}
	int k1 = n;
	int k2;
	vector<pair<int, int>> ans;
	if (n % 2 == 1)
	{
		k2 = 1;
		for (int i = 1; i <= n; i++)
		{
			if (dp[k1][i] + a[i] < dp[k1][k2] + a[k2])
			{
				k2 = i;
			}
		}
	}
	else
	{
		k1--;
		k2 = 1;
		for (int i = 1; i <= n; i++)
		{
			if (dp[k1][i] + max(a[i], a[n]) < dp[k1][k2] + max(a[k2], a[n]))
			{
				k2 = i;
			}
		}
	}
	ans.emplace_back(k2, k2);
	while (k1)
	{
		auto [k3, k4] = pre[k1][k2];
		if (k3 == 0 || k4 == 0) break;
		vector<int> v1 = { k1,k4,k1 - 1 };
		v1.erase(find(v1.begin(), v1.end(), k2));
		ans.emplace_back(v1[0], v1[1]);
		k1 = k3;
		k2 = k4;
	}
	reverse(ans.begin(), ans.end());
	if (n % 2 == 0)
		ans.back().second = n;
	int sum = 0;
	for (auto& [l, r] : ans)
	{
		sum += max(a[l], a[r]);
	}
	printf("%d\n", sum);
	for (auto& [l, r] : ans)
	{
		if (l == r) printf("%d\n", l);
		else printf("%d %d\n", l, r);
	}
	return 0;
}