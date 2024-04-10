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
class SegmentTree
{
public:
	LL addv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
	}
	LL query(int l, int r, int o = 1)
	{
		LL ret = addv[o];
		if (l == r)
		{
			return ret;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (mid < qr) ret += query(mid + 1, r, o << 1 | 1);
		return ret;
	}
} st;
vector<int> v[N];
vector<pair<int, int>> qr[N];
int depth[N];
int h = 0;
LL ans[N];
void dfs(int x, int fa = 0)
{
	depth[x] = depth[fa] + 1;
	h = max(h, depth[x]);
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
}
void solve(int x, int fa = 0)
{
	int l = depth[x];
	for (auto &p : qr[x])
	{
		int r;
		int val;
		tie(r, val) = p;
		st.set(l, r, val);
		st.add(1, h);
	}
	st.set(l, l);
	ans[x] = st.query(1, h);
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		solve(y, x);
	}
	for (auto &p : qr[x])
	{
		int r;
		int val;
		tie(r, val) = p;
		st.set(l, r, -val);
		st.add(1, h);
	}
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
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x, d, val;
		scanf("%d%d%d", &x, &d, &val);
		d = min(h, depth[x] + d);
		qr[x].push_back({ d,val });
	}
	solve(1);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}