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
const int N = 1e4 + 10;
int deg[N];
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
int check(vector<tuple<int, int, int>> &vp, int key = -1)
{
	uf.init();
	for (int i = 0; i < vp.size(); i++)
	{
		if (i == key) continue;
		int x, y, w;
		tie(x, y, w) = vp[i];
		if (uf.Find(x) == uf.Find(y)) continue;
		uf.Union(x, y);
	}
	int ret = 0;
	for (int o = 1; o <= 4; o++)
	{
		if (uf.Find(o) != o) continue;
		int sum = 0;
		for (int i = 0; i < vp.size(); i++)
		{
			if (i == key) continue;
			int x, y, w;
			tie(x, y, w) = vp[i];
			if (uf.Find(x) == uf.Find(o))
			{
				sum += w;
			}
		}
		ret = max(ret, sum);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<tuple<int, int, int>> vp;
	int n;
	cin >> n;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int x, w, y;
		cin >> x >> w >> y;
		if (x > y) swap(x, y);
		tot += w;
		vp.push_back({ x,y,w });
		deg[x]++;
		deg[y]++;
	}
	int cnt = 0;
	for (int i = 1; i <= 4; i++) cnt += deg[i] & 1;
	if (cnt <= 2)
	{
		printf("%d\n", check(vp));
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = i + 1; j <= 4; j++)
		{
			pair<int, int> minv = { int(INF),-1};
			for (int o = 0; o < vp.size(); o++)
			{
				auto &p = vp[o];
				int x, y, w;
				tie(x, y, w) = p;
				if (x == i && y == j)
				{
					minv = min(minv, make_pair(w, o));
				}
			}
			if (minv.second == -1) continue;
			ans = max(ans, check(vp, minv.second));
		}
	}
	printf("%d\n", ans);
	return 0;
}