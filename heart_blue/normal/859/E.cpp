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
const int N = 2e6 + 10;
vector<int> v1[N], v2[N];
int flag[N];
int dfs1(int x)
{
	if (flag[x]) return 0;
	flag[x] = 1;
	int ret = 1;
	for (auto& y : v2[x])
	{
		ret += dfs1(y);
	}
	return ret;
}

int dfs2(int x)
{
	flag[x] = 1;
	int ret = 1;
	for (auto& y : v2[x])
	{
		ret += dfs2(y);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v1[x].push_back(y);
		v2[y].push_back(x);
	}
	LL ans = 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (flag[i]) continue;
		if (v1[i].empty()) continue;
		vector<int> v;
		int x = i;
		while (flag[x] < 2)
		{
			v.push_back(x);
			flag[x]++;
			if (v1[x].empty()) break;
			x = v1[x][0];
		}
		if (flag[x] == 2)
		{
			int len = 0;
			for (auto& y : v)
			{
				len += flag[y] / 2;
			}
			len /= 2;
			for (auto& y : v)
				flag[y] = 0;
			int tot = dfs1(x);
			if (len != 1)
				ans = ans * 2 % INF;
		}
		else
		{
			ans = ans * dfs2(x) % INF;
		}
	}
	printf("%lld\n", ans);
	return 0;
}