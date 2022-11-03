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
const int N = 1e5 + 10;
vector<int> vv[N];
struct Edge
{
	int x, y, w, o;
	bool operator < (Edge &e)
	{
		if (y != e.y) return y < e.y;
		if (w != e.w) return w < e.w;
		return o < e.o;
	}
};
vector<Edge> vp1, vp2;
int pos[N];
int l[N], r[N];
class SegmentTree
{
public:
	int ql, qr, qx;
	int maxv[N * 4];
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			maxv[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		int mid = (l + r) >> 1;
		int ret = 0;
		if (ql <= mid) ret = max(ret, query(l, mid, o << 1));
		if (mid < qr) ret = max(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	MEM(l, 0x3f);
	MEM(r, 0);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vv[y].push_back(w);
		vp1.push_back(Edge{ x, y, w, i });
	}
	for (int i = 1; i <= n; i++)
	{
		if (vv[i].empty()) continue;
		sort(vv[i].begin(), vv[i].end());
	}
	vp2 = vp1;
	sort(vp2.begin(), vp2.end());
	for (int i = 0; i < vp2.size(); i++)
	{
		pos[vp2[i].o] = i + 1;
		int y = vp2[i].y;
		l[y] = min(l[y], i + 1);
		r[y] = max(r[y], i + 1);
	}
	int ans = 0;
	for (auto &e : vp1)
	{
		int x = e.x;
		int y = e.y;
		int w = e.w;
		int p = pos[e.o];
		int ret = 1;
		if (!vv[x].empty())
		{
			int L = l[x];
			int oo = (lower_bound(vv[x].begin(), vv[x].end(), w) - vv[x].begin());
			int R = l[x] + oo - 1;
			if (L <= R && R <= m)
			{
				st.set(L, R);
				ret += st.query(1, m);
			}
		}
		st.set(p, p, ret);
		st.update(1, m);
		ans = max(ans, ret);
	}
	cout << ans << endl;
	return 0;
}