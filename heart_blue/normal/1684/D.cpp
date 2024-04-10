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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class SegmentTree
{
public:
	pair<LL, int> minv[N * 4];
	LL addv[N * 4];
	int ql, qr;
	LL qx;
	void init(int n)
	{
		fill(addv, addv + 4 * n + 10, 0LL);
		fill(minv, minv + 4 * n + 10, make_pair(0LL, 0));
	}
	void set(int l, int r, LL x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	inline void pushdown(int l, int r, int o)
	{
		if (addv[o])
		{
			addv[o << 1] += addv[o];
			addv[o << 1 | 1] += addv[o];
			minv[o << 1].first += addv[o];
			minv[o << 1 | 1].first += addv[o];
			addv[o] = 0;
		}
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			minv[o].first += qx;
			return;
		}
		pushdown(l, r, o);
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] = 0;
			minv[o].second = qx;
			return;
		}
		pushdown(l, r, o);
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	pair<LL, int> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return minv[o];
		}
		pushdown(l, r, o);
		int mid = (l + r) / 2;
		pair<LL, int> ret = { INF * INF,0 };
		if (ql <= mid) ret = min(query(l, mid, o << 1), ret);
		if (mid < qr) ret = min(query(mid + 1, r, o << 1 | 1), ret);
		return ret;
	}
} st;
int a[N];
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
		int k;
		scanf("%d", &k);

		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			ans += a[i];
		}
		st.init(n);
		for (int i = 1; i <= n; i++)
		{
			st.set(i, i, -a[i] + n - i);
			st.add(1, n);
			st.set(i, i, i);
			st.update(1, n);
		}
		for (int i = k; i >= 1; i--)
		{
			st.set(1, n);
			auto [sum, pos] = st.query(1, n);
			ans += sum;
			st.set(1, n, -1);
			st.add(1, n);
			st.set(pos, pos, INF * INF);
			st.add(1, n);
		}
		printf("%lld\n", ans);
	}
	return 0;
}