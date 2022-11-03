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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class SegmentTree
{
	pair<LL, int> sumv[N * 4];
	int ql, qr, qx;
public:
	void init(int n)
	{
		fill(sumv, sumv + 4 * n + 5, make_pair(0LL, 0));
	}
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			sumv[o].first = qx;
			sumv[o].second = 1;
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		sumv[o].first = sumv[o << 1].first + sumv[o << 1 | 1].first;
		sumv[o].second = sumv[o << 1].second + sumv[o << 1 | 1].second;
	}
	LL query(int l, int r, int o = 1)
	{
		if (qx == 0) return 0;
		if (sumv[o].second <= qx)
		{
			qx -= sumv[o].second;
			return sumv[o].first;
		}
		int mid = (l + r) / 2;
		LL ret = 0;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (mid < qr) ret += query(mid + 1, r, o << 1 | 1);
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		LL t;
		scanf("%d%d%lld", &n, &m, &t);
		vector<pair<int, int>> vp;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			vp.emplace_back(x, i);
		}
		sort(vp.rbegin(), vp.rend());
		st.init(n);
		pair<int, int> maxv = { 0, (int)min(t,1LL * vp.back().first) };
		int sz = 0;
		while (!vp.empty())
		{
			int x = vp.back().first;
			while (!vp.empty() && vp.back().first == x)
			{
				int pos = vp.back().second;
				vp.pop_back();
				st.set(pos, pos, x);
				st.add(1, n);
				sz++;
			}
			if (x > t) break;
			int l, r;
			l = 0, r = sz / m;
			int cnt1 = 0;
			LL cost = 0;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				st.set(1, n, mid * m);
				LL tot = st.query(1, n);
				if (tot * 2 <= t) cnt1 = mid * m, cost = tot, l = mid + 1;
				else r = mid - 1;
			}
			l = cnt1 + 1;
			r = min(sz, l + m - 1);
			int ans = cnt1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				st.set(1, n, mid);
				LL tot = st.query(1, n);
				if (tot - cost <= t - 2 * cost) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			maxv = max(maxv, make_pair(ans, x));
		}
		printf("%d %d\n", maxv.first, maxv.second);
	}
	return 0;
}