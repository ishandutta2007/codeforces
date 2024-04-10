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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<pair<int, int>> vp;
		int n;
		scanf("%d", &n);
		int p;
		scanf("%d", &p);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			vp.emplace_back(a[i], i);
		}
		sort(vp.begin(), vp.end());
		uf.init(n + 1);
		LL ans = 0;
		int tot = n - 1;
		for (auto [val, id] : vp)
		{
			if (val >= p) break;
			for (int i = id - 1; i >= 1; i--)
			{
				if (a[i] % val) break;
				if (uf.Find(i) == uf.Find(id)) break;
				uf.Union(i, id);
				ans += val;
				tot--;
			}
			for (int i = id + 1; i <= n; i++)
			{
				if (a[i] % val) break;
				if (uf.Find(i) == uf.Find(id)) break;
				uf.Union(i, id);
				ans += val;
				tot--;
			}
		}
		printf("%lld\n", ans + 1LL * tot * p);
	}
	return 0;
}