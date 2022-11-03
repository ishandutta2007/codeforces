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
const int N = 3e5 + 10;
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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<tuple<int, int, int>> vp;
		for (int i = 1; i <= m; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			vp.emplace_back(w, x, y);
		}
		sort(vp.begin(), vp.end());
		uf.init(n + 1);
		LL ans = INF * INF;
		LL tot = 0;
		for (auto [w, x, y] : vp)
		{
			if (uf.Find(x) != uf.Find(y))
			{
				uf.Union(x, y);
				if (w > k)
				{
					tot += w - k;
					if (uf.treesize(1) == n)
						ans = min(ans, tot);
				}
			}
			if (uf.treesize(1) == n)
			{
				if (w <= k)
					ans = min(ans, 1LL * k - w);
				else
				{
					ans = min(ans, tot + w - k);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}