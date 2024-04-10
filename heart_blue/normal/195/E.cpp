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
const int N = 2e5 + 10;
class UnionFind
{
public:
	int p[N];
	int val[N];
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
		int tot = 0;
		while (p[s] >= 0)
		{
			tot += val[s];
			if (tot >= INF) tot -= INF;
			s = p[s];
		}
		while (x != s)
		{
			int t = p[x];
			int tval = val[x];
			val[x] = tot;
			tot -= tval;
			if (tot < 0) tot += INF;
			p[x] = s;
			x = t;
		}
		return s;
	}
	int getval(int x)
	{
		Find(x);
		return val[x];
	}
	void Union(int x, int y, int v = 0)
	{
		x = Find(x);
		y = Find(y);

		p[y] += p[x];
		p[x] = y;
		val[x] = v;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n;
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int sz;
		scanf("%d", &sz);
		while (sz--)
		{
			int v, x;
			scanf("%d%d", &v, &x);
			x += uf.getval(v);
			if (x < 0) x += INF;
			if (x >= INF) x -= INF;
			uf.Union(uf.Find(v), i, x);
			ans += x;
		}
	}
	printf("%lld\n", ans % INF);
	return 0;
}