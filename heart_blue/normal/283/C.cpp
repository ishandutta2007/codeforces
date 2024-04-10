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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
const int M = 1e5;
int deg[N];
int a[N];
int nex[N];
int pre[N];
int dis[N];
int dp[M];
int sum[M];
int n, q, t;
void dfs(int x, vector<int>& v)
{
	if (dis[x] != -1) return;
	v.push_back(x);
	dis[x] = 0;
	if (nex[x])
	{
		dfs(nex[x], v);
		dis[x] = dis[nex[x]] + 1;
		t -= dis[x] * a[x];
		if (t < 0)
		{
			puts("0");
			exit(0);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &q, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	MEM(dis, -1);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		nex[x] = y;
		deg[y] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
		{
			vector<int> v;
			dfs(i, v);
			//reverse(v.begin(), v.end());
			while (!v.empty())
			{
				int x = v.back();
				v.pop_back();
				for (auto& y : v)
					a[x] += a[y];
			}
		}
	}
	if (count(dis + 1, dis + n + 1, -1) > 0)
	{
		puts("0");
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int w = a[i];
		for (int j = 0; j <= t; j++)
		{
			sum[j] = dp[j];
			if (j >= w)
			{
				sum[j] += sum[j - w];
				if (sum[j] >= INF)
					sum[j] -= INF;
			}
			dp[j] = sum[j];
		}
	}
	printf("%d\n", dp[t]);

	return 0;
}