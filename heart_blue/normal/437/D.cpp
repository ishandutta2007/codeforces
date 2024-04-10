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
class UnionSet
{
public:
	int fa[N];
	void init()
	{
		MEM(fa, -1);
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
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
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
	}
} uf;
vector < pair<int, pair<int, int>>> vp;
int w[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		vp.push_back({ min(w[x],w[y]),{x,y} });
	}
	LL ans = 0;
	sort(vp.rbegin(), vp.rend());
	for (auto &p : vp)
	{
		int ww = p.first;
		int x, y;
		tie(x, y) = p.second;
		if (uf.Find(x) != uf.Find(y))
		{
			ans += 1LL * uf.treesize(x)*uf.treesize(y)*ww;
			uf.Union(x, y);
		}
	}
	printf("%.15f\n", ans*2.0 / n / (n - 1));
	return 0;
}