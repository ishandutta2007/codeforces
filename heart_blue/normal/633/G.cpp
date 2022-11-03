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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 1e3 + 10;
bitset<1000> flag;
vector<int> v[N];
int dfn = 0;
int in[N], out[N];
int a[N];
int n, m;
void init()
{
	for (int i = 2; i < m; i++)
	{
		flag[i] = flag[i] ^ 1;
		if (flag[i] == 0) continue;
		for (int j = i + i; j < m; j += i) flag[j] = 1;
	}
}
void dfs(int x, int p = -1)
{
	in[x] = ++dfn;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
	out[x] = dfn;
}
class SegmentTree
{
public:
	bitset<1000> b[N * 4];
	int addv[N * 4];
	int ql, qr, qx;
	inline void set(int l, int r, int x = -1)
	{
		ql = l, qr = r, qx = x;
	}
	inline void shift(bitset<1000> &b, int o)
	{
		if (o > m) while (1);
		b = (b << o) | (b >> (m - o));
	}
	inline void pushdown(int o)
	{
		if (addv[o])
		{
			shift(b[o << 1], addv[o]);
			shift(b[o << 1 | 1], addv[o]);
			addv[o << 1] += addv[o];
			if (addv[o << 1] >= m) addv[o << 1] -= m;
			addv[o << 1 | 1] += addv[o];
			if (addv[o << 1 | 1] >= m) addv[o << 1 | 1] -= m;
			addv[o] = 0;
		}
	}
	inline void maintain(int o)
	{
		b[o] = b[o << 1] | b[o << 1 | 1];
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			b[o][qx] = 1;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (qr > mid) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			if (addv[o] >= m) addv[o] -= m;
			shift(b[o], qx);
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= mid) add(l, mid, o << 1);
		if (qr > mid) add(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	bitset<1000> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return b[o];
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		bitset<1000> ret;
		if (ql <= mid) ret |= query(l, mid, o << 1);
		if (qr > mid) ret |= query(mid + 1, r, o << 1 | 1);
		maintain(o);
		return ret;
	}
}st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
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
		st.set(in[i], in[i], a[i]%m);
		st.update(1, n);
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int u, x;
			scanf("%d%d", &u, &x);
			st.set(in[u], out[u], x%m);
			st.add(1, n);
		}
		else
		{
			int u;
			scanf("%d", &u);
			st.set(in[u], out[u]);
			printf("%d\n", (st.query(1, n) & flag).count());
		}
	}
	return 0;
}