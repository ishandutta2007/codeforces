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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
char str[N];
char c[N];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;
int dis[N];
map<int, int> mc[N];
int dfs(int x)
{
	if (dis[x] != -1)
		return dis[x];
	return dis[x] = 1 + dfs(a[x]);
}
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
int id(int x, int y)
{
	return x * m + y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d", &n, &m);
		uf.init(n * m);
		memset(dis, -1, sizeof(int) * n * m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", c + i * m);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < m; j++)
			{
				int o = 0;
				if (str[j] == 'U') o = 0;
				if (str[j] == 'D') o = 1;
				if (str[j] == 'L') o = 2;
				if (str[j] == 'R') o = 3;
				int x = id(i, j);
				int y = id(i + dx[o], j + dy[o]);
				if (uf.Find(x) != uf.Find(y))
					uf.Union(x, y);
				a[x] = y;
			}
		}
		int ans = 0;
		map<int, int> len;
		for (int i = 0; i < n * m; i++)
		{
			if (uf.Find(i) != i) continue;
			mc[i].clear();
			int x = i, y = i;
			while (1)
			{
				x = a[x];
				y = a[a[y]];
				if (x == y)
					break;
			}
			int cnt = 0;
			while (1)
			{
				cnt++;
				ans++;
				x = a[x];
				if (x == y)
					break;
			}
			len[i] = cnt;
			dis[x] = 0;
		}
		for (int i = 0; i < n * m; i++)
		{
			int p = uf.Find(i);
			int l = len[p];
			mc[p][dfs(i) % l] |= (c[i] & 1) ^ 1;
		}
		int tot = 0;
		for (int i = 0; i < n * m; i++)
		{
			if (uf.Find(i) != i) continue;
			for (auto& p : mc[i])
				tot += p.second;
		}
		printf("%d %d\n", ans, tot);
	}
	return 0;
}