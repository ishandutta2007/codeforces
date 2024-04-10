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
const int N = 1e5 + 10;
int n, k;
vector<int> vp, v[N], ans[2];
int depth[N];
void dfs(int x, int fa = 0)
{
	depth[x] = depth[fa] + 1;
	ans[depth[x] & 1].push_back(x);
	vp.push_back(x);
	int t = 0;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		if (depth[y] > depth[t])
		{
			t = y;
		}
	}
	if (t != 0 && depth[t] != 0)
	{
		vector<int> key;
		for (int i = depth[t] - 1; i < vp.size(); i++)
		{
			key.push_back(vp[i]);
		}
		if (key.size() <= k)
		{
			puts("2");
			printf("%d\n", key.size());
			for (auto& x : key)
				printf("%d ", x);
			puts("");
		}
		else
		{
			puts("1");
			for (int i = 0; i < (k + 1) / 2 * 2; i += 2)
			{
				printf("%d ", key[i]);
			}
			puts("");
		}
		exit(0);
	}
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		if (depth[y] == 0)
			dfs(y, x);
	}
	vp.pop_back();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	int o = 0;
	if (ans[o].size() < ans[o ^ 1].size()) o ^= 1;
	puts("1");
	for (int i = 0; i < (k + 1) / 2; i++)
	{
		printf("%d ", ans[o][i]);
	}
	return 0;
}