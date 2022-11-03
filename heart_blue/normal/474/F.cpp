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
const int N = 1e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
class SegmentTree
{
public:
	int g[N * 4];
	int minv[N * 4];
	int cnt[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = -1)
	{
		ql = l, qr = r, qx = x;
	}
	void init()
	{
		MEM(g, 0);
		MEM(minv, 0x3f);
		MEM(cnt, 0);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			g[o] = qx;
			minv[o] = qx;
			cnt[o] = 1;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (qr > mid) update(mid + 1, r, o << 1 | 1);
		g[o] = gcd(g[o << 1], g[o << 1 | 1]);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
		cnt[o] = 0;
		if (g[o] == minv[o << 1]) cnt[o] += cnt[o << 1];
		if (g[o] == minv[o << 1 | 1]) cnt[o] += cnt[o << 1 | 1];
	}
	tuple<int, int, int> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return { g[o], minv[o], cnt[o] };
		}
		int gval = 0;
		int ret = 0;
		int m = 0;
		int g1 = 0, g2 = 0, r1 = 0, r2 = 0, m1 = INF, m2 = INF;
		int mid = (l + r) >> 1;
		if (mid >= ql) tie(g1, m1, r1) = query(l, mid, o << 1);
		if (qr > mid) tie(g2, m2, r2) = query(mid + 1, r, o << 1 | 1);
		gval = gcd(g1, g2);
		m = min(m1, m2);
		if (gval == m1) ret += r1;
		if (gval == m2) ret += r2;
		return { gval,m, ret };
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	st.init();
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		st.set(i, i, x);
		st.update(1, n);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		st.set(l, r);
		printf("%d\n", r - l + 1 - get<2>(st.query(1, n)));
	}
	return 0;
}