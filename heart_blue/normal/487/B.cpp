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
class SegmentTree
{
public:
	int val[N*4];
	int minv[N*4];
	int maxv[N*4];
	int ql, qr, qx;
	int maxx, minx;
	SegmentTree()
	{
		MEM(val, 0);
		MEM(minv, 0x3f);
		MEM(maxv, 0xaf);
	}
	void set(int l, int r, int x = 0, int maxx = -INF, int minx = INF)
	{
		ql = l, qr = r, qx = x;
		this->maxx = maxx;
		this->minx = minx;
	}
	void updateVal(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			val[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) updateVal(l, mid, o << 1);
		if (qr > mid) updateVal(mid + 1, r, o << 1 | 1);
		val[o] = min(val[o << 1], val[o << 1 | 1]);
	}
	int queryVal(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return val[o];
		}
		int mid = (l + r) >> 1;
		int ret1 = INF, ret2 = INF;
		if (ql <= mid) ret1 = queryVal(l, mid, o << 1);
		if (qr > mid) ret2 = queryVal(mid + 1, r, o << 1 | 1);
		return min(ret1, ret2);
	}
	void updateMv(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			minv[o] = qx;
			maxv[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) updateMv(l, mid, o << 1);
		if (qr > mid) updateMv(mid + 1, r, o << 1 | 1);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			if (max(maxx, maxv[o]) - min(minx, minv[o]) <= qx)
			{
				maxx = max(maxx, maxv[o]);
				minx = min(minx, minv[o]);
				return l;
			}
		}
		if (l == r) return INF;
		int mid = (l + r) >> 1;
		int ret1 = INF, ret2 = INF;
		int flag = 0;
		if (qr > mid) flag = 1, ret2 = query(mid + 1, r, o << 1 | 1);
		if ((flag == 0 || ret2 == mid + 1) && ql <= mid) ret1 = query(l, mid, o << 1);
		return min(ret1, ret2);
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s, len;
	cin >> n >> s >> len;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		st.set(i, i, x);
		st.updateMv(1, n);
	}
	for (int i = 1; i <= n; i++)
	{
		st.set(i, i, INF);
		st.updateVal(1, n);
	}
	if (len <= n)
	{
		st.set(1, len, s);
		if (st.query(1, n) == 1)
		{
			st.set(len, len, 1);
			st.updateVal(1, n);
		}
	}
	for (int i = len + 1; i <= n; i++)
	{
		st.set(1, i, s);
		int l = st.query(1, n);
		if (i - l + 1 >= len)
		{
			if (l == 1)
			{
				st.set(i, i, 1);
				st.updateVal(1, n);
				continue;
			}
			st.set(l - 1, i - len);
			int x = st.queryVal(1, n);
			st.set(i, i, x + 1);
			st.updateVal(1, n);
		}
	}
	st.set(n, n);
	int ans = st.queryVal(1, n);
	if (ans > n) ans = -1;
	printf("%d\n", ans);
	return 0;
}