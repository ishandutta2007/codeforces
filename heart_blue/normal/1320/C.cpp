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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
class SegmentTree
{
public:
	int addv[N];
	int maxv[N];
	int ql, qr, qx;
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
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			maxv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		pushdown(o);
		int mid = (l + r) / 2;
		int ret = 2 * INF;
		if (ql <= mid) ret = max(ret, query(l, mid, o << 1));
		if (mid < qr) ret = max(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	vector<pair<int, int>> v1(n), v2(m);
	for (auto& [x, y] : v1) scanf("%d%d", &x, &y);
	for (auto& [x, y] : v2) scanf("%d%d", &x, &y);
	vector<tuple<int, int, int>> vp(p);
	for (auto& [x, y, z] : vp)
		scanf("%d%d%d", &x, &y, &z);
	sort(vp.begin(), vp.end());
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v2.size(); i++)
	{
		st.set(i + 1, i + 1, -v2[i].second);
		st.add(1, m);
	}
	int ans = -INF * 2;
	int ptr = 0;
	for (auto& [x, cost] : v1)
	{
		while (ptr < vp.size())
		{
			auto [a, b, c] = vp[ptr];
			if (a >= x) break;
			ptr++;
			int pos = lower_bound(v2.begin(), v2.end(), make_pair(b + 1, -1)) - v2.begin();
			pos++;
			if (pos <= m)
			{
				st.set(pos, m, c);
				st.add(1, m);
			}
		}
		st.set(1, m);
		ans = max(ans, st.query(1, n) - cost);
	}
	printf("%d\n", ans);
	return 0;
}