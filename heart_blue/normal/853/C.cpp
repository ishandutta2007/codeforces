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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
class SegmentTree
{
public:
	vector<int> v[N * 4];
	int ql, qr, qx, qy;
	void set(int l, int r, int x = 0, int y = 0)
	{
		ql = l, qr = r, qx = x, qy = y;
	}
	void build(int l, int r, int o = 1)
	{
		for (int i = l; i <= r; i++)
		{
			v[o].push_back(a[i]);
		}
		sort(v[o].begin(), v[o].end());
		if (l == r) return;
		int mid = (l + r) / 2;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return upper_bound(v[o].begin(), v[o].end(), qy) - lower_bound(v[o].begin(), v[o].end(), qx);
		}
		int mid = (l + r) / 2;
		int ret = 0;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (mid < qr) ret += query(mid + 1, r, o << 1 | 1);
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	st.build(1, n);
	while (q--)
	{
		int l, d, r, u;
		scanf("%d%d%d%d", &l, &d, &r, &u);
		vector<pair<int, int>> vp;
		vp.emplace_back(n, 1);
		vp.emplace_back(l - 1, -1);
		vp.emplace_back(n - r, -1);
		vp.emplace_back(d - 1, -1);
		vp.emplace_back(n - u, -1);
		vector<tuple<int, int, int, int>> qr;
		qr.emplace_back(1, l - 1, 1, d - 1);
		qr.emplace_back(1, l - 1, u + 1, n);
		qr.emplace_back(r + 1, n, 1, d - 1);
		qr.emplace_back(r + 1, n, u + 1, n);
		for (auto [l, r, x, y] : qr)
		{
			if (l > r || x > y) continue;
			st.set(l, r, x, y);
			vp.emplace_back(st.query(1, n), 1);
		}
		LL ans = 0;
		for (auto& [x, o] : vp)
		{
			ans += o * 1LL * x * (x - 1) / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}