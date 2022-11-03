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
#include <cassert>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
const LL inf = 0x3f3f3f3f3f3f3f3f;
class SegmentTree
{
public:
	int ql, qr;
	LL qx;
	LL addv[N * 4];
	LL minv[N * 4];
	void init()
	{
		MEM(minv, 0x3f);
	}
	void set(int l, int r, LL x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	inline void pushdown(int o)
	{
		if (addv[o])
		{
			addv[o << 1] += addv[o];
			addv[o << 1 | 1] += addv[o];
			minv[o << 1] += addv[o];
			minv[o << 1 | 1] += addv[o];
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
		LL ret1 = inf, ret2 = inf;
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		maintain(o);
		return min(ret1, ret2);
	}
} st;
char str[N];
LL sum(LL l, LL r)
{
	if (l > r) return 0;
	r = r * (r + 1) / 2;
	l = l * (l - 1) / 2;
	return r - l;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str + 1);
	LL ans = sum(1, n);
	vector<int> v;
	set<int> s;
	st.init();
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == '1')
			v.push_back(i);
		s.insert(i);
	}
	for (int i = n; i >= 1; i--)
	{
		if (str[i] != '1') continue;
		LL res = i + sum(i + k + 1, n);
		auto iter1 = s.lower_bound(i + k + 1);
		while (iter1 != s.end())
		{
			int cur = *iter1;
			auto iter2 = lower_bound(v.begin(), v.end(), cur + k + 1);
			if (iter2 == v.end()) break;
			st.set(*iter2, n, cur);
			st.add(1, n);
			s.erase(cur);
			iter1 = s.lower_bound(cur);
		}
		st.set(i, n);
		res = min(res, st.query(1, n) + i);
		st.set(i, i, res - inf);
		st.add(1, n);
		ans = min(ans, res + sum(1, i - k - 1));
	}
	printf("%lld\n", ans);
	return 0;
}