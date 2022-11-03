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
vector<int> v[N];
int core[N];
int price[N];
class SegmentTree
{
public:
	LL cnt[N * 4];
	LL cost[N * 4];
	int ql, qr, qx, qy;
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			cnt[o] += qx;
			cost[o] = cnt[o] * l;
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		cnt[o] = cnt[o << 1] + cnt[o << 1 | 1];
		cost[o] = cost[o << 1] + cost[o << 1 | 1];
	}
	LL query(int l, int r, int o = 1)
	{
		if (qx == 0) return 0;
		if (cnt[o] <= qx)
		{
			qx -= cnt[o];
			return cost[o];
		}
		if (l == r)
		{
			int minv = min(qx, int(cnt[o]));
			qx -= minv;
			return cost[o] / cnt[o] * minv;
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
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	int maxv = 0;
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		scanf("%d%d%d%d", &l, &r, &core[i], &price[i]);
		maxv = max(maxv, price[i]);
		v[l].push_back(i);
		v[r + 1].push_back(-i);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (auto& id : v[i])
		{
			int c = core[abs(id)];
			int p = price[abs(id)];
			if (id < 0)
			{
				st.set(p, p, -c);
				st.update(1, maxv);
			}
			else
			{
				st.set(p, p, c);
				st.update(1, maxv);
			}
		}
		st.set(1, maxv, k);
		LL res = st.query(1, maxv);
		ans += res;
		//cout << res << endl;
	}
	printf("%lld\n", ans);
	return 0;
}