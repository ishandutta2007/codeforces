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
const int N = 4e6 + 10;
const LL MOD = 998244353;
int readint() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9')c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int)*n);
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
int pos[N];
int tot[N];
int deg[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = readint();
	uf.init();
	int k = 0;
	vector<pair<int, int>> vp;
	map<int, int> mc;
	for (int i = 0; i < n; i++)
	{
		int x = readint();
		int y = readint();
		if (!mc.count(x)) mc[x] = ++k;
		if (!mc.count(y)) mc[y] = ++k;
		pos[mc[x]] = x;
		pos[mc[y]] = y;
		x = mc[x];
		y = mc[y];
		vp.push_back({ x,y });
		deg[x]++;
		deg[y]++;
		if (uf.Find(x) != uf.Find(y))
			uf.Union(x, y);
	}
	for (auto &p : vp)
	{
		int x, y;
		tie(x, y) = p;
		tot[uf.Find(x)]++;
	}
	for (int i = 1; i <= k; i++)
	{
		if (uf.Find(i) != i) continue;
		if (tot[i] > uf.treesize(i))
		{
			puts("-1");
			return 0;
		}
	}
	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		int p = uf.Find(i);
		if (tot[p] == uf.treesize(p))
		{
			ans = max(ans, pos[i]);
		}
		else
		{
			v[p].push_back(pos[i]);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		if (v[i].empty()) continue;
		sort(v[i].begin(), v[i].end());
		v[i].pop_back();
		ans = max(ans, v[i].back());
	}
	printf("%d\n", ans);

	return 0;
}