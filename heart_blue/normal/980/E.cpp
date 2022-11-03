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
const int N = 1e6 + 10;
vector<int> v[N];
int flag[N];
int fa[N][22];
int depth[N];
void dfs(int x, int p = 0)
{
	fa[x][0] = p;
	depth[x] = depth[p] + 1;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
void init(int n)
{
	dfs(n);
	for (int o = 1; o < 22; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o] = fa[fa[i][o - 1]][o - 1];
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	k = n - k;
	init(n);
	flag[0] = 1;
	flag[n] = 1;
	k--;
	for (int i = n - 1; i > 0; i--)
	{
		int x = i;
		for (int o = 21; o >= 0; o--)
		{
			if (flag[fa[x][o]] == 0)
			{
				x = fa[x][o];
			}
		}
		if (depth[i] - depth[x] + 1 <= k)
		{
			int x = i;
			while (flag[x] == 0)
			{
				flag[x] = 1;
				x = fa[x][0];
				k--;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 0)
			printf("%d ", i);
	}
	return 0;
}