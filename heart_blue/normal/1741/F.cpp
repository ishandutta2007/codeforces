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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e5 + 10;
class Segment
{
public:
	int maxv[N * 4];
	int addv[N * 4];
	int ql, qr, qx;
	void init(int n)
	{
		fill(maxv, maxv + (4 * n + 4), 0);
		fill(addv, addv + (4 * n + 4), 0);
	}
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void pushdown(int o)
	{
		if (addv[o])
		{
			addv[o << 1] += addv[o];
			addv[o << 1 | 1] += addv[o];
			maxv[o << 1] += addv[o];
			maxv[o << 1 | 1] += addv[o];
			addv[o] = 0;
		}
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			maxv[o] += qx;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(o);
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	int querymax(int l, int r, int o = 1)
	{
		if (maxv[o] == 0) return 0;
		if (l == r)
		{
			return l;
		}
		int ret = 0;
		int mid = (l + r) / 2;
		pushdown(o);
		if (mid < qr) ret = querymax(mid + 1, r, o << 1 | 1);
		if (ret) return ret;
		if (ql <= mid) ret = querymax(l, mid, o << 1);
		return ret;
	}
	int querymin(int l, int r, int o = 1)
	{
		if (maxv[o] == 0) return 0;
		if (l == r)
		{
			return l;
		}
		int ret = 0;
		int mid = (l + r) / 2;
		pushdown(o);
		if (ql <= mid) ret = querymin(l, mid, o << 1);
		if (ret) return ret;
		if (mid < qr) ret = querymin(mid + 1, r, o << 1 | 1);
		return ret;
	}
} st;
vector<int> key;
vector<tuple<int, int, int>> vp[N];
int ans[N];
int build(int n)
{
	key.clear();
	for (int i = 1; i <= n; i++)
	{
		for (auto [l, r, id] : vp[i])
		{
			key.push_back(l);
			key.push_back(r);
		}
	}
	sort(key.begin(), key.end());
	int sz = key.size();
	st.init(sz);
	key.resize(unique(key.begin(), key.end()) - key.begin());
	key.insert(key.begin(), 0);
	for (int i = 1; i <= n; i++)
	{
		for (auto& [l, r, id] : vp[i])
		{
			l = lower_bound(key.begin(), key.end(), l) - key.begin();
			r = lower_bound(key.begin(), key.end(), r) - key.begin();
			st.set(l, r, 1);
			st.update(1, sz);
		}
	}
	return sz;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			vp[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			vp[c].emplace_back(x, y, i);
		}
		int sz = build(n);
		for (int i = 1; i <= n; i++)
		{
			for (auto& [l, r, id] : vp[i])
			{
				st.set(l, r, -1);
				st.update(1, sz);
			}
			for (auto& [l, r, id] : vp[i])
			{
				st.set(l, r);
				int ret = st.querymax(1, sz);
				if (ret)
				{
					ans[id] = 0;
					continue;
				}
				st.set(1, l);
				int pos1 = st.querymax(1, sz);
				st.set(r, sz);
				int pos2 = st.querymin(1, sz);
				int res = INF;
				if (pos1) res = min(res, key[l] - key[pos1]);
				if (pos2) res = min(res, key[pos2] - key[r]);
				ans[id] = res;
			}
			for (auto& [l, r, id] : vp[i])
			{
				st.set(l, r, 1);
				st.update(1, sz);
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}