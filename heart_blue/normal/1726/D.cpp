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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char ans[N];
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
		if (px == py) return;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	random_device rd;
	mt19937 g(rd());
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<tuple<int, int, int>> vp;
		vp.reserve(m);
		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vp.emplace_back(x, y, i);
		}
		ans[m] = 0;
		int cnt = 50;
		while (cnt--)
		{
			shuffle(vp.begin(), vp.end(), g);
			uf.init(n + 1);
			fill(ans, ans + m, '0');
			vector<pair<int, int>> key;
			int tot = 0;
			for (auto& [x, y, id] : vp)
			{
				if (uf.Find(x) != uf.Find(y))
					uf.Union(x, y), tot++, ans[id] = '1';
				else
					key.emplace_back(x, y);
			}
			uf.init(n + 1);
			for (auto& [x, y] : key)
			{
				if (uf.Find(x) != uf.Find(y))
					uf.Union(x, y), tot++;
			}
			if (tot == m) break;
		}
		puts(ans);
	}
	return 0;
}