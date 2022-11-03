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
	int maxv[N * 4];
	int minv[N * 4];
	int addv[N * 4];
	int ql, qr, qx;
public:
	void init(int n)
	{
		fill(maxv, maxv + 4 * (n + 2) + 1, 0);
		fill(minv, minv + 4 * (n + 2) + 1, 0);
		fill(addv, addv + 4 * (n + 2) + 1, 0);
	}
	void set(int l, int r, int x = 0)
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
			maxv[l] += addv[o];
			maxv[r] += addv[o];
			addv[o] = 0;
		}
	}
	inline void maintain(int o)
	{
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			minv[o] += qx;
			maxv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	int query()
	{
		return maxv[1] - minv[1] + 1;
	}
} st;
pair<int, int> solve(vector<int>& v)
{
	for (auto& x : v) x = -x;
	int n = v.size();
	int tot = n + 1;
	st.init(tot);
	for (int i = 0; i < n; i++)
	{
		st.set(i + 2, tot, v[i]);
		st.add(0, tot);
	}
	int ret1 = st.query();
	int ret2 = ret1;
	for (int i = 0; i < n; i++)
	{
		st.set(i + 1, tot, 1);
		st.add(0, tot);
		ret2 = min(ret2, st.query());
		if (i + 1 != n)
		{
			st.set(i + 2, tot, -v[i]);
			st.add(0, tot);
			st.set(i + 1, tot, v[i] - 1);
			st.add(0, tot);
		}
	}
	ret1 = max(ret1, 1);
	ret2 = max(ret2, 1);
	return { ret1,ret2 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		vector<int> v1, v2;
		for (auto& c : str)
		{
			if (c == 'W') v1.push_back(1);
			if (c == 'S') v1.push_back(-1);
			if (c == 'A') v2.push_back(1);
			if (c == 'D') v2.push_back(-1);
		}
		vector<pair<int, int>> vp1, vp2;
		vp1.push_back(solve(v1));
		vp1.push_back(solve(v1));
		vp2.push_back(solve(v2));
		vp2.push_back(solve(v2));
		LL ans = INF * INF;
		for (auto& p1 : vp1)
		{
			for (auto& p2 : vp2)
			{
				ans = min({ ans,1LL * p1.first * p2.second,1LL * p1.second * p2.first });
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}