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
const int N = 5e5 + 10;

class SegmentTree
{
public:
	int ql, qr, qx;
	int setv[N * 4];
	int sumv[N * 4];
	void init()
	{
		MEM(setv, -1);
		MEM(sumv, 0);
	}
	void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	void pushdown(int o)
	{
		if (setv[o] != -1)
		{
			setv[o << 1] = setv[o];
			setv[o << 1 | 1] = setv[o];
			sumv[o << 1] = setv[o];
			sumv[o << 1 | 1] = setv[o];
			setv[o] = -1;
		}
	}
	void maintain(int o)
	{
		sumv[o] = sumv[o << 1] | sumv[o << 1 | 1];
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr) return sumv[o];
		pushdown(o);
		int mid = (l + r) >> 1;
		int ret = 0;
		if (ql <= mid) ret |= query(l, mid, o << 1);
		if (mid < qr) ret |= query(mid + 1, r, o << 1 | 1);
		maintain(o);
		return ret;
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
} st;
vector<int> v[N];
int in[N];
int out[N];
int fa[N];
int cnt = 0;
void dfs(int x, int p = -1)
{
	fa[x] = p;
	in[x] = ++cnt;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
	out[x] = cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	st.set(1, n, 1);
	st.update(1, n);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if (op == 1)
		{
			st.set(in[x], out[x]);
			if (st.query(1, n) && fa[x] != -1)
			{
				st.set(in[fa[x]], in[fa[x]], 1);
				st.update(1, n);
			}
			st.set(in[x], out[x], 0);
			st.update(1, n);
		}
		else if (op == 2)
		{
			st.set(in[x], in[x], 1);
			st.update(1, n);
		}
		else
		{
			st.set(in[x], out[x]);
			printf("%d\n", st.query(1, n) ^ 1);
		}
	}
	return 0;
}