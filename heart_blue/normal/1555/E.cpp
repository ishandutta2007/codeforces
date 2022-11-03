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
const int N = 1e6 + 10;
class SegmentTree
{
public:
	int minv[N * 4];
	int addv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	inline void pushdown(int o)
	{
		if (addv[o])
		{
			minv[o << 1] += addv[o];
			minv[o << 1 | 1] += addv[o];
			addv[o << 1] += addv[o];
			addv[o << 1 | 1] += addv[o];
			addv[o] = 0;
		}
	}
	inline void maintain(int o)
	{
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			minv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	int query()
	{
		return minv[1];
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	m--;
	vector<tuple<int, int, int>> vp(n);
	for (auto& [w, l, r] : vp)
	{
		scanf("%d%d%d", &l, &r, &w);
		r--;
	}
	sort(vp.begin(), vp.end());
	int maxv = 0;
	int ptr = 0;
	int ans = INF;
	for (int i = 0; i < vp.size(); i++)
	{
		auto [w1, l1, r1] = vp[i];
		maxv = max(maxv, w1);
		while (ptr < vp.size() && st.query() != 1)
		{
			auto [w2, l2, r2] = vp[ptr];
			st.set(l2, r2, 1);
			st.update(1, m);
			ptr++;
			maxv = max(maxv, w2);
		}
		if (st.query() == 1)
			ans = min(ans, maxv - w1);
		st.set(l1, r1, -1);
		st.update(1, m);
	}
	printf("%d\n", ans);
	return 0;
}