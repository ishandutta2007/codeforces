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
const int N = 4e5 + 10;
class SegmentTree
{
public:
	LL setv[N * 4];
	LL sumv[N * 4];
	int ql, qr;
	LL qx;
	void set(int l, int r, LL x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	inline void maintain(int o)
	{
		sumv[o] = sumv[o << 1] | sumv[o << 1 | 1];
	}
	inline void pushdown(int o)
	{
		if (setv[o])
		{
			setv[o << 1] = setv[o << 1 | 1] = setv[o];
			sumv[o << 1] = sumv[o << 1 | 1] = setv[o];
			setv[o] = 0;
		}
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = sumv[o] = qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	LL query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return sumv[o];
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		LL ret = 0;
		if (ql <= mid) ret |= query(l, mid, o << 1);
		if (mid < qr) ret |= query(mid + 1, r, o << 1 | 1);
		maintain(o);
		return ret;
	}
} st;
int in[N];
int out[N];
vector<int> v[N];
int cnt = 0;
void dfs(int x, int p = -1)
{
	in[x] = ++cnt;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
	out[x] = cnt;
}
int getans(LL x)
{
	int ret = 0;
	while (x) x -= x & -x, ret++;
	return ret;
}
int clr[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &clr[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		st.set(in[i], in[i], 1LL << clr[i]);
		st.update(1, n);
	}
	while (m--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int v, c;
			scanf("%d%d", &v, &c);
			st.set(in[v], out[v], 1LL << c);
			st.update(1, n);
		}
		else
		{
			int v;
			scanf("%d", &v);
			st.set(in[v], out[v]);
			printf("%d\n", getans(st.query(1, n)));
		}
	}
	return 0;
}