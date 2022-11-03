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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class SegmentTree
{
	LL minv[N * 4];
	LL addv[N * 4];
	int ql, qr;
	LL qx;
public:

	void set(int l, int r, LL x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	inline void pushdown(int o)
	{
		if (addv[o])
		{
			int l = o << 1;
			int r = o << 1 | 1;
			addv[l] += addv[o];
			addv[r] += addv[o];
			minv[l] += addv[o];
			minv[r] += addv[o];
			addv[o] = 0;
		}
	}
	inline void maintain(int o)
	{
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			minv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	LL query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return minv[o];
		}
		pushdown(o);
		int mid = (l + r) / 2;
		LL ret = INF * INF;
		if (ql <= mid) ret = min(ret, query(l, mid, o << 1));
		if (mid < qr) ret = min(ret, query(mid + 1, r, o << 1 | 1));
		maintain(o);
		return ret;
	}
} st1, st2;
vector<int> v[N];
int pos[N * 2];
int w1[N];
int w2[N];
int n;
int in[N];
int out[N];
int cnt = 0;
void dfs(int x, LL sum = 0)
{
	in[x] = ++cnt;
	sum += w1[x];
	st1.set(cnt, cnt, sum);
	st1.add(1, n);
	st2.set(cnt, cnt, sum + w2[x]);
	st2.add(1, n);
	for (auto& y : v[x])
	{
		dfs(y, sum);
	}
	out[x] = cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		w1[y] = w;
		pos[i - 1] = y;
		v[x].push_back(y);
	}
	for (int i = 2; i <= n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		w2[x] = w;
		pos[n - 1 + i - 1] = x;
	}
	dfs(1);
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int id, w;
			scanf("%d%d", &id, &w);
			int x = pos[id];
			if (id <= n - 1)
			{
				int delta = w - w1[x];
				st1.set(in[x], out[x], delta);
				st1.add(1, n);
				st2.set(in[x], out[x], delta);
				st2.add(1, n);
				w1[x] = w;
			}
			else
			{
				int delta = w - w2[x];
				st2.set(in[x], in[x], delta);
				st2.add(1, n);
				w2[x] = w;
			}
		}
		else
		{
			int x, y;
			scanf("%d%d", &x, &y);
			st1.set(in[y], in[y]);
			LL len2 = st1.query(1, n);
			st1.set(in[x], in[x]);
			LL len1 = st1.query(1, n);
			if (in[x] <= in[y] && in[y] <= out[x])
			{
				printf("%lld\n", len2 - len1);
			}
			else
			{
				st2.set(in[x], out[x]);
				LL len3 = st2.query(1, n);
				printf("%lld\n", len2 + len3 - len1);
			}
		}
	}
	return 0;
}