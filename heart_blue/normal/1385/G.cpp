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
		if (Find(x) == Find(y)) return;
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
vector<int> v[N];
vector<int> vp[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) v[i].clear();
		memset(flag, 0, sizeof(int) * (2 * n + 10));
		for (int i = 1; i <= 2 * n + 1; i++)
		{
			vp[i].clear();
		}
		for (int o = 0; o < 2; o++)
		{
			for (int i = 1; i <= n; i++)
			{
				int x;
				scanf("%d", &x);
				v[x].push_back(i * 2 + o);
			}
		}
		uf.init(n * 2 + 10);
		int ok = 1;
		for (int i = 1; i <= n; i++)
		{
			if (v[i].size() != 2)
			{
				ok = 0;
				continue;
			}
			int x = v[i][0];
			int y = v[i][1];
			if ((x & 1) == (y & 1))
			{
				x |= 1;
				y |= 1;
				uf.Union(x, y ^ 1);
				uf.Union(x ^ 1, y);
			}
			else
			{
				x |= 1;
				y |= 1;
				uf.Union(x ^ 1, y ^ 1);
				uf.Union(x, y);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (uf.Find(i * 2) == uf.Find(i * 2 + 1))
				ok = 0;
		}
		if (ok == 0)
		{
			puts("-1");
			continue;
		}
		vector<int> ans;
		for (int i = 3; i <= 2 * n + 1; i += 2)
		{
			vp[uf.Find(i)].push_back(i / 2);
		}
		for (int i = 2; i <= 2 * n + 1; i += 2)
		{
			int x = uf.Find(i);
			int y = uf.Find(i + 1);
			if (flag[x] || flag[y]) continue;
			flag[x] = flag[y] = 1;
			vector<int>* key = &vp[x];
			if (vp[x].size() > vp[y].size())
				key = &vp[y];
			for (auto& x : *key)
				ans.push_back(x);
		}
		printf("%d\n", ans.size());
		for (auto& x : ans)
			printf("%d ", x);
		puts("");
	}
	return 0;
}