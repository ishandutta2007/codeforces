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
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
class UnionSet
{
public:
	int fa[N * 4];
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

class SegmentTree
{
	int ql, qr, qx;
	int val[N * 4];
public:
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void build(int l, int r, int o = 1)
	{
		if (l == r)
		{
			val[o] = l;
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
	}
	void pushdown(int l, int r, int o, int v)
	{
		if (val[o] == 0) return;
		if (l == r) return;
		int mid = (l + r) >> 1;
		if (val[o << 1] == 0)
		{
			val[o << 1] = v;
			pushdown(l, mid, o << 1, v);
		}
		else
		{
			if (uf.Find(v) != uf.Find(val[o << 1]))
				uf.Union(v, val[o << 1]);
		}
		if (val[o << 1 | 1] == 0)
		{
			val[o << 1 | 1] = v;
			pushdown(mid + 1, r, o << 1 | 1, v);
		}
		else
		{
			if (uf.Find(v) != uf.Find(val[o << 1 | 1]))
				uf.Union(v, val[o << 1 | 1]);
		}
	}
	int query(int l, int r, int o = 1)
	{
		if (l <= ql && qr <= r)
		{
			if (val[o])
				return uf.Find(val[o]);
		}
		int mid = (l + r) >> 1;
		int ret = 0;
		if (ql <= mid) ret = query(l, mid, o << 1);
		if (mid < qr) ret = query(mid + 1, r, o << 1 | 1);
		return ret;
	}
	void update(int l, int r, int o = 1)
	{
		if (val[o])
		{
			if (uf.Find(val[o]) != uf.Find(qx))
				uf.Union(val[o], qx);
			return;
		}
		if (ql <= l && r <= qr)
		{
			if (val[o])
			{
				if (uf.Find(val[o]) != uf.Find(qx))
					uf.Union(val[o], qx);
			}
			else
			{
				val[o] = qx;
				pushdown(l, r, o, qx);
			}
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	uf.init();
	st.build(1,n);
	while (q--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)
		{
			st.set(x, x);
			int px = st.query(1, n);
			st.set(y, y, px);
			st.update(1, n);
			continue;
		}
		if (op == 2)
		{
			st.set(x, x);
			int px = st.query(1, n);
			st.set(x, y, px);
			st.update(1, n);
			continue;
		}
		if (op == 3)
		{
			st.set(x, x);
			int px = st.query(1, n);
			st.set(y, y);
			int py = st.query(1, n);
			if (px == py) puts("YES");
			else puts("NO");
		}

	}
	return 0;
}