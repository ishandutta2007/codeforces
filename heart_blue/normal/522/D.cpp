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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
class SegmentTree
{
	int minv[N*4];
	int ql, qr, qx;
public:
	void init()
	{
		MEM(minv, 0x3f);
	}
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			minv[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return minv[o];
		}
		int mid = (l + r) >> 1;
		int ret = 0x3f3f3f3f;
		if (ql <= mid) ret = min(ret, query(l, mid, o << 1));
		if (mid < qr) ret = min(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int a[N];
vector<pair<int, int>> qr[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		qr[r].push_back({ l,i });
	}
	st.init();
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		if (mc.count(a[i]))
		{
			int pos = mc[a[i]];
			st.set(pos, pos, i - pos);
			st.update(1, n);
		}
		mc[a[i]] = i;
		for (auto &p : qr[i])
		{
			int l, r, pos;
			tie(l, pos) = p;
			r = i;
			st.set(l, r);
			ans[pos] = st.query(1, n);
			if (ans[pos] == 0x3f3f3f3f) ans[pos] = -1;
		}
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}