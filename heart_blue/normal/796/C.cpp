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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int maxv[N * 4];
int w[N];
int ql, qr, qx;
int in[N];
int out[N];
int fa[N];
int cnt[N];
int dfn = 0;
int n;
vector<int> v[N];
void bfs(int x, int p = -1)
{
	fa[x] = -1;
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cnt[x] = ++dfn;
		for (auto &y : v[x])
		{
			if (y == fa[x]) continue;
			fa[y] = x;
			q.push(y);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		in[i] = INF;
		out[i] = 0;
		for (auto &x : v[i])
		{
			if (x == fa[i]) continue;
			in[i] = min(in[i], cnt[x]);
			out[i] = max(out[i], cnt[x]);
		}
		if (in[i] == INF) out[i] = in[i] - 1;
	}
}
void update(int l, int r, int o = 1)
{
	maxv[o] = -INF;
	if (ql <= l && r <= qr)
	{
		maxv[o] = qx;
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid) update(l, mid, o << 1);
	if (qr > mid) update(mid + 1, r, o << 1 | 1);
	maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
}
int query(int l, int r, int o = 1)
{
	if (ql > qr) return -INF;
	if (ql <= l && r <= qr)
	{
		return maxv[o];
	}
	if (l == r)
	{
		return -INF;
	}
	int mid = (l + r) >> 1;
	int maxv = -INF;
	if (ql <= mid) maxv = max(maxv, query(l, mid, o << 1));
	if (qr > mid) maxv = max(maxv, query(mid + 1, r, o << 1 | 1));
	return maxv;
}
int getans(int l, int r)
{
	ql = l, qr = r;
	return query(1, n);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1);
	for (int i = 1; i <= n; i++)
	{
		ql = qr = cnt[i];
		qx = w[i];
		update(1, n);
	}
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		int mv = w[i];
		if (fa[i] == -1)
		{
			mv = max(mv, getans(in[i], out[i]) + 1);
			mv = max(mv, getans(out[i] + 1, n) + 2);
		}
		else
		{
			int pl = cnt[fa[i]];
			mv = max(mv, w[fa[i]] + 1);
			mv = max(mv, getans(1, pl - 1) + 2);
			mv = max(mv, getans(pl + 1, cnt[i] - 1) + 2);
			mv = max(mv, getans(cnt[i] + 1, in[i] - 1) + 2);
			mv = max(mv, getans(in[i], out[i]) + 1);
			mv = max(mv, getans(out[i] + 1, n) + 2);
		}
		ans = min(ans, mv);
	}
	printf("%d\n", ans);
	return 0;
}