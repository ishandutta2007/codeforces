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
int minv[N];
int maxv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
		}
	}
	for (int i = 1; i <= n; i++) minv[i] = maxv[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int p = uf.Find(i);
		minv[p] = min(i, minv[p]);
		maxv[p] = max(i, maxv[p]);
	}
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) == i)
			vp.emplace_back(minv[i], maxv[i]);
	}
	int l = 0, r = 0;
	sort(vp.begin(), vp.end());
	vp.emplace_back(N, N);
	int ans = 0;
	for (auto& p : vp)
	{
		int x, y;
		tie(x, y) = p;
		if (r >= x) r = max(r, y);
		else
		{
			for (int i = l; i < r; i++)
			{
				if (uf.Find(i) != uf.Find(i + 1))
					ans++, uf.Union(i, i + 1);
			}
			l = x, r = y;
		}
	}
	printf("%d\n", ans);
	return 0;
}