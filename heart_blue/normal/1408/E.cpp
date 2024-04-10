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
vector<int> v[N];
int a[N];
int b[N];
vector<tuple<int, int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	LL tot = 0;
	for (int i = 1; i <= m; i++)
	{
		int sz;
		scanf("%d", &sz);
		while (sz--)
		{
			int x;
			scanf("%d", &x);
			vp.emplace_back(a[i] + b[x], i, x);
			tot += a[i] + b[x];
		}
	}
	sort(vp.rbegin(), vp.rend());
	uf.init();
	for (auto& p : vp)
	{
		int cost, x, y;
		tie(cost, x, y) = p;
		if (v[x].empty())
		{
			tot -= cost;
			v[x].push_back(y);
		}
		else
		{
			if (uf.Find(y) == uf.Find(x + n)) continue;
			if (uf.Find(y) == uf.Find(v[x].back())) continue;
			if (uf.Find(y) != uf.Find(x + n))
				uf.Union(y, x + n);
			if (uf.Find(y) != uf.Find(v[x].back()))
				uf.Union(y, v[x].back());
			v[x].push_back(y);
			tot -= cost;
		}
	}
	printf("%lld\n", tot);
	return 0;
}