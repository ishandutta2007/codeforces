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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	vector<tuple<int, int, int>> vp;
	while (--m)
	{
		int l, r, z;
		scanf("%d%d%d", &l, &r, &z);
		vp.emplace_back(z, l, r);
	}
	sort(vp.begin(), vp.end());
	int ans = 1e9;
	uf.init();
	for (auto& [c, a, b] : vp)
	{
		if (uf.Find(x) != uf.Find(y))
		{
			ans = c;
		}
		if (uf.Find(a) != uf.Find(b))
			uf.Union(a, b);
	}
	if (uf.Find(x) != uf.Find(y))
		ans = 1e9;
	printf("%d\n", ans);
	return 0;
}