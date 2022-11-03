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
const int N = 5e5 + 10;
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int t = p[x];
			p[x] = s;
			x = t;
		}
		return s;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
vector<int> v[N];
void dfs(int x)
{
	if (uf.Find(x) != uf.Find(0))
	{
		uf.Union(x, 0);
		for (auto& y : v[x])
		{
			dfs(y);
		}
		v[x].clear();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	uf.init();
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		int sz;
		scanf("%d", &sz);
		if (sz == 1)
		{
			int x;
			scanf("%d", &x);
			if (uf.Find(x) == uf.Find(0)) continue;
			ans.push_back(i);
			dfs(x);
		}
		else
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (uf.Find(x) == uf.Find(y)) continue;
			if (uf.Find(x) == uf.Find(0)) dfs(y);
			else if (uf.Find(y) == uf.Find(0)) dfs(x);
			else
				v[x].push_back(y), v[y].push_back(x);
			if (uf.Find(x) != uf.Find(y))
				uf.Union(x, y);
			ans.push_back(i);
		}
	}
	int tot = 1;
	for (int i = 0; i < ans.size(); i++)
	{
		tot = tot * 2 % INF;
	}
	printf("%d %d\n", tot, ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}