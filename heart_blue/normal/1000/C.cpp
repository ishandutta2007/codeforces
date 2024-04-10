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
const int N = 6 * 2e5 + 10;
class SegmentTree
{
public:
	int addv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
	}
	void pushdown(int o)
	{
		if (addv[o])
		{
			addv[o << 1] += addv[o];
			addv[o << 1 | 1] += addv[o];
			addv[o] = 0;
		}
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return addv[o];

		}
		pushdown(o);
		int mid = (l + r) >> 1;
		int ret = 0;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (mid < qr) ret += query(mid + 1, r, o << 1 | 1);
		return ret;
	}
} st;
vector<LL> v;
vector<pair<LL, LL>> vp;
LL ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vp.resize(n);
	map<LL, int> mc;
	for (auto &p : vp)
	{
		scanf("%lld%lld", &p.first, &p.second);
		for (int i = -1; i <= 1; i++)
		{
			mc[p.first + i] = 1;
			mc[p.second + i] = 1;
		}
	}
	for (auto &p : mc)
		v.push_back(p.first);
	int len = v.size() + 10;
	for (auto &p : vp)
	{
		LL l, r;
		tie(l, r) = p;
		int L = lower_bound(v.begin(), v.end(), l) - v.begin();
		int R = lower_bound(v.begin(), v.end(), r) - v.begin();
		st.set(L, R, 1);
		st.update(1, len);
	}
	for (int i = 1; i + 1 < v.size(); i++)
	{
		st.set(i, i, 0);
		int cnt = st.query(1, len);
		ans[cnt] += v[i + 1] - v[i];
	}
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}