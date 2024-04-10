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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class SegmentTree
{
public:
	int sumv[N * 4];
	int setv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	inline void pushdown(int l, int r, int o)
	{
		if (setv[o] != -1)
		{
			setv[o << 1] = setv[o << 1 | 1] = setv[o];
			int mid = (l + r) / 2;
			sumv[o << 1] = (mid - l + 1) * setv[o];
			sumv[o << 1 | 1] = (r - mid) * setv[o];
			setv[o] = -1;
		}
	}
	inline void maintain(int l, int r, int o)
	{
		sumv[o] = sumv[o << 1] + sumv[o << 1 | 1];
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = qx;
			sumv[o] = (r - l + 1) * qx;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(l, r, o);
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(l, r, o);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return sumv[o];
		}
		int mid = (l + r) / 2;
		pushdown(l, r, o);
		int ret = 0;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (mid < qr) ret += query(mid + 1, r, o << 1 | 1);
		maintain(l, r, o);
		return ret;
	}
} st;
char s1[N], s2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		scanf("%s%s", s1 + 1, s2 + 1);
		vector<pair<int, int>> vp(q);
		for (auto& [x, y] : vp)
			scanf("%d%d", &x, &y);
		reverse(vp.begin(), vp.end());
		for (int i = 1; i <= n; i++)
		{
			st.set(i, i, s2[i] - '0');
			st.update(1, n);
		}
		int flag = 1;
		for (auto& [l, r] : vp)
		{
			st.set(l, r);
			int cnt1 = st.query(1, n);
			int cnt0 = r - l + 1 - cnt1;
			if (cnt0 > cnt1) st.set(l, r, 0);
			else if (cnt0 < cnt1) st.set(l, r, 1);
			else
			{
				flag = 0;
				break;
			}
			st.update(1, n);
		}
		for (int i = 1; i <= n; i++)
		{
			st.set(i, i);
			if (st.query(1, n) != s1[i] - '0')
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0) puts("NO");
		else puts("YES");

	}
	return 0;
}