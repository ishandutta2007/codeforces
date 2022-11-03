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
const int M = 5e5 + 10;
class SegmentTree
{
	int ql, qr, qx;
	int maxv[N * 4];
public:
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			maxv[o] = qx;
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		int mid = (l + r) / 2;
		int ret1 = 0, ret2 = 0;
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		return max(ret1, ret2);
	}
} st;
class BIT
{
public:
	int a[N];
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b;
vector<int> vp[N];
pair<int, int> e[N];
pair<int, int> qr[M];
int flag[N];
int w[N];
int depth[N];
int fa[N][20];
int in[N];
int out[N];
int pos[N];
int vis[N];
int cnt = 0;
void dfs(int x, int p = 0)
{
	in[x] = ++cnt;
	pos[cnt] = x;
	fa[x][0] = p;
	depth[x] = depth[p] + 1;
	for (auto& y : vp[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
	out[x] = cnt;
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
			dfs(i);
	}
	for (int o = 1; o < 20; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o] = fa[fa[i][o - 1]][o - 1];
		}
	}
}
int query(int x)
{
	for (int o = 19; o >= 0; o--)
	{
		int y = fa[x][o];
		if (y == 0) continue;
		if (depth[y] - depth[x] == b.sum(in[y]) - b.sum(in[x])) x = y;
	}
	return x;
}
class UnionFind
{
public:
	int p[N];
	int val[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
		for (int i = 0; i < N; i++)
			val[i] = i;
	}
	int getval(int x)
	{
		return val[Find(x)];
	}
	void setval(int x, int v)
	{
		val[Find(x)] = v;
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

void refrain(int m)
{
	vector<int> v;
	for (int i = 1; i <= m; i++)
	{
		if (flag[i]) v.push_back(flag[i]);
	}
	sort(v.begin(), v.end());
	while (!v.empty() && v.back() == INF) v.pop_back();
	int cnt = v.size();
	for (int i = 1; i <= m; i++)
	{
		if (flag[i] == 0) continue;
		if (flag[i] == INF)
		{
			flag[i] = ++cnt;
			continue;
		}
		flag[i] = lower_bound(v.begin(), v.end(), flag[i]) - v.begin() + 1;
	}
}
void build(int i, int n, int &len)
{
	int u, v;
	tie(u, v) = e[i];
	if (uf.Find(u) != uf.Find(v))
	{
		len++;
		int val1 = uf.getval(u);
		int val2 = uf.getval(v);
		vis[val1] = 1;
		vis[val2] = 1;
		int val = uf.getval(flag[i] + n);
		uf.Union(val1, val2);
		uf.Union(val, val1);
		vp[val].push_back(val1);
		vp[val].push_back(val2);
		uf.setval(val, val);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u = w[u];
		v = w[v];
		e[i] = make_pair(u, v);
	}
	for (int i = 1; i <= q; i++)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if (op == 1) x = w[x];
		qr[i] = make_pair(op, x);
		if (op == 2)
		{
			flag[x] = i;
		}
	}
	uf.init();
	int len = n;
	vector<int> vp;
	for (int i = 1; i <= m; i++)
	{
		if (flag[i]) continue;
		int u, v;
		tie(u, v) = e[i];
		if (uf.Find(u) != uf.Find(v))
		{
			vp.push_back(i);
			uf.Union(e[i].first, e[i].second);
			flag[i] = INF;
		}
	}
	for (int i = q; i >= 1; i--)
	{
		if (qr[i].first == 2)
		{
			int u, v;
			tie(u, v) = e[qr[i].second];
			if (uf.Find(u) != uf.Find(v))
			{
				uf.Union(u, v);
				vp.push_back(qr[i].second);
			}
			else
				flag[qr[i].second] = 0;
		}
	}
	refrain(m);
	uf.init();
	for (auto& x : vp)
	{
		build(x, n, len);
	}
	init(len);
	for (int i = 1; i <= len; i++)
		b.add(i, depth[pos[i]] - depth[pos[i - 1]]);
	for (int i = 1; i <= len; i++)
	{
		st.set(in[i], in[i], i <= n ? i : 0);
		st.update(1, len);
	}
	for (int i = 1; i <= q; i++)
	{
		int o, x;
		tie(o, x) = qr[i];
		if (o == 1)
		{
			x = query(x);
			st.set(in[x], out[x], 0);
			int key = st.query(1, len);
			printf("%d\n", key);
			if (key == 0) continue;
			st.set(in[key], in[key], 0);
			st.update(1, len);
		}
		else
		{
			if (flag[x] == 0) continue;
			x = flag[x] + n;
			b.add(in[x] + 1, -1);
			b.add(out[x] + 1, 1);
		}
	}
	return 0;
}