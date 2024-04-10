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
class Node
{
public:
	int u, v, w;
	int o;
	int pos;
	Node(int u = 0, int v = 0, int w = 0, int o = 0, int pos = 0)
	{
		this->u = u;
		this->v = v;
		this->w = w;
		this->o = o;
		this->pos = pos;
	}
	bool operator < (const Node &node) const
	{
		if (w != node.w) return w < node.w;
		return o > node.o;
	}
};
vector<Node> vp;
pair<int, int> ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vp.resize(m);
	uf.init();
	for (int i = 0; i < m; i++)
	{
		cin >> vp[i].w >> vp[i].o;
		vp[i].pos = i;
	}
	sort(vp.begin(), vp.end());
	int k = 2;
	int x = 2, y = 3;
	for (int i = 0; i < m; i++)
	{
		if (vp[i].o == 0)
		{
			vp[i].u = x;
			vp[i].v = y;
			ans[vp[i].pos] = { x++,y };
			if (x == y)
			{
				x = 2;
				y++;
			}
		}
		else
		{
			vp[i].u = 1;
			vp[i].v = k;
			ans[vp[i].pos] = { 1,k++ };
		}
	}
	for (auto &node : vp)
	{
		int x, y, o;
		x = node.u;
		y = node.v;
		o = node.o;
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
			if (o == 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}