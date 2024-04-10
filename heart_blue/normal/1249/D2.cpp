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
const int N = 2e5 + 10;
class SegmentTree
{
public:
	int addv[N*4];
	int maxv[N*4];
	int ql, qr, qx;
	void set(int l, int r, int x = 1)
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
	void maintain(int o)
	{
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			maxv[o] += qx;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(o);
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		int mid = (l + r) / 2;
		pushdown(o);
		int ret = 0;
		if (ql <= mid) ret = max(ret, query(l, mid, o << 1));
		if (mid < qr) ret = max(ret, query(mid + 1, r, o << 1 | 1));
		maintain(o);
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	vector<tuple<int, int, int>> vp;
	int len = 1;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		len = max(len, r);
		vp.emplace_back(r, l, i);
	}
	sort(vp.begin(), vp.end());
	vector<int> ans;
	for (auto& p : vp)
	{
		int l, r, id;
		tie(r, l, id) = p;
		st.set(l, r);
		if (st.query(1, len) == k)
		{
			ans.push_back(id);
			continue;
		}
		st.set(l, r);
		st.update(1, len);
	}
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}