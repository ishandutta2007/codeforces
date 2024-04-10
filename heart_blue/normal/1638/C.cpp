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
const int N = 2e5 + 20;
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
		if (x == y) return;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int a[N];
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
		uf.init(n + 1);
		map<int, int> mc;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			mc[a[i]] = i;
		}
		int minv = INF;
		while (!mc.empty())
		{
			auto [x, pos] = *mc.rbegin();
			if (x > minv) uf.Union(minv, x);
			minv = min(minv, x);
			for (int i = pos; i <= n; i++)
			{
				if (a[i] > x) break;
				minv = min(minv, a[i]);
				mc.erase(a[i]);
				uf.Union(x, a[i]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (uf.Find(i) == i)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}