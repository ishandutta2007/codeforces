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
const int N = 4e5 + 10;
class UnionFind
{
public:
	int p[N];
	int val[N];
	void init(int n = N)
	{
		fill(p + 1, p + n * 2 + 1, -1);
		for (int i = 1; i <= n; i++)
			val[i] = 1, val[i + n] = 0;

	}
	int getval(int x)
	{
		return val[Find(x)];
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
		if (px == py) return;
		int tot = val[px] + val[py];
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
		val[px] = tot;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		uf.init(n);
		while (m--)
		{
			int x, y;
			char str[20];
			scanf("%d%d%s", &x, &y, str);
			if (str[0] == 'i')
			{
				uf.Union(x, y + n);
				uf.Union(x + n, y);
			}
			else
			{
				uf.Union(x, y);
				uf.Union(x + n, y + n);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (uf.Find(i) == uf.Find(i + n))
			{
				ans = -1;
				break;
			}
			if (uf.Find(i) == i)
			{
				ans += max(uf.getval(i), uf.getval(i + n));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}