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
const int N = 3e5 + 10;
class UnionSet
{
public:
	int fa[N];
	int s[N];
	void init(int n = N)
	{
		memset(fa, -1, sizeof(int) * n);
		memset(s, 0, sizeof(int) * n);
	}
	void add(int x)
	{
		s[x] = 1;
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
	}
	int getsize(int x)
	{
		return s[Find(x)];
	}
	int Find(int x)
	{
		int root = x;
		while (fa[root] >= 0) root = fa[root];
		while (x != root)
		{
			int tmp = fa[x];
			fa[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		int res = s[px] + s[py];
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
		s[px] = res;
	}
} uf;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	uf.init();
	for (int i = 0; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		uf.add(x);
	}
	vector<tuple<int, int, int>> vp;
	int ans = 0;
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp.emplace_back(w, x, y);
	}
	sort(vp.begin(), vp.end());
	for (auto& p : vp)
	{
		int w, x, y;
		tie(w, x, y) = p;
		ans = w;
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
		}
		if (uf.getsize(x) == k)
			break;
	}
	while (k--)
		printf("%d ", ans);
	return 0;
}