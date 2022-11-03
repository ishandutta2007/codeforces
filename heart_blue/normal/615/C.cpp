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
const int N = 3e3 + 10;
char s1[N], s2[N];
int dp[N][N];
pair<int, pair<int, int>> ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	for (int i = n; i > 0; i--)
	{
		for (int j = m; j > 0; j--)
		{
			dp[i][j] = 0;
			if (s1[i] == s2[j])
			{
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			ans[j] = max(ans[j], { dp[i][j],{i,i + dp[i][j] - 1} });
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j > 0; j--)
		{
			dp[i][j] = 0;
			if (s1[i] == s2[j])
			{
				dp[i][j] = 1 + dp[i - 1][j + 1];
			}
			ans[j] = max(ans[j], { dp[i][j],{i,i - dp[i][j] + 1} });
		}
	}
	vector<pair<int, int>> res;
	int cur = 1;
	while (cur <= m)
	{
		int step = ans[cur].first;
		if (step == 0)
		{
			cout << -1 << endl;
			return 0;
		}
		if (cur + step - 1 <= m)
		{
			res.push_back(ans[cur].second);
			cur += step;
		}
		else
		{
			step = m - cur + 1;
			int l, r;
			tie(l, r) = ans[cur].second;
			if (l <= r) r = l + step - 1;
			else r = l - step + 1;
			res.push_back({ l,r });
			break;
		}
	}
	printf("%d\n", res.size());
	for (auto &p : res)
	{
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}