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
const int N = 1e5 + 10;
int sum[N][2][2];
char str[N];
int cost[N];
pair<int, int> edge[N];
int dp[N];
int check(int l, int r)
{
	int o = l & 1;
	if (sum[r][o][1] - sum[l - 1][o][1] > 0) return INF;
	if (sum[r][o ^ 1][0] - sum[l - 1][o ^ 1][0] > 0) return INF;
	int tot = sum[r][o][0] - sum[l - 1][o][0] +
		sum[r][o ^ 1][1] - sum[l - 1][o ^ 1][1];
	return r - l + 1 - tot;
}
int build(vector<pair<int, int>> vp, int m)
{
	int sz = 0;
	int cur = 0;
	for (int i = 0; i < vp.size(); i++)
	{
		if (vp[i].first < cur) continue;
		edge[++sz].first = i + 1;
		cur = vp[i].first + m;
	}
	cur = INF;
	for (int i = sz; i >= 1; i--)
	{
		while (!vp.empty() && vp.back().first > cur)
		{
			vp.pop_back();
		}
		edge[i].second = vp.size();
		cur = vp.back().first - m;
	}
	return sz;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	int m;
	scanf("%d", &m);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
		if (isalpha(str[i]))
			sum[i][i & 1][str[i] - 'a']++;
	}

	for (int i = 1; i + m - 1 <= n; i++)
	{
		int res = check(i, i + m - 1);
		if (res == INF) continue;
		vp.emplace_back(i, res);
	}
	if (vp.empty())
	{
		puts("0");
		return 0;
	}
	int sz = build(vp, m);
	vp.insert(vp.begin(), make_pair(0, 0));
	int ans = INF;
	for (int i = 1; i <= sz; i++)
	{
		int pre = INF;
		if (i == 1)
		{
			for (int j = edge[i].first; j <= edge[i].second; j++)
			{
				dp[j] = min(pre, vp[j].second);
				pre = min(pre, dp[j]);
			}
		}
		else
		{
			int x = i - 1;
			int y = i;
			int ptr = edge[x].first;
			int minv = INF;
			for (int j = edge[y].first; j <= edge[y].second; j++)
			{
				while (ptr <= edge[x].second && vp[ptr].first + m <= vp[j].first)
				{
					minv = min(minv, dp[ptr++]);
				}
				dp[j] = min(pre, minv + vp[j].second);
				pre = min(pre, dp[j]);
			}
		}
		if (i == sz)
			ans = pre;
	}
	printf("%d\n", ans);
	return 0;

}