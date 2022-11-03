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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
class SemmentTree
{
public:
	int cnt[N * 4];
	LL sumv[N * 4];
	int minv[N * 4];
	int rval[N * 4];
	int ql, qr, qx, qy;
	void init()
	{
		MEM(cnt, 0);
		MEM(sumv, 0);
		MEM(minv, 0);
		fill(rval, rval + (N * 4), INF);
	}
	void set(int l, int r, int x, int y = 1)
	{
		ql = l, qr = r, qx = x, qy = y;
	}
	void maintain(int o)
	{
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
		sumv[o] = sumv[o << 1] + sumv[o << 1 | 1];
		cnt[o] = cnt[o << 1] + cnt[o << 1 | 1];
		if (rval[o << 1 | 1] != INF) rval[o] = rval[o << 1 | 1];
		else rval[o] = rval[o << 1];
	}
	void add(int l, int r, int o = 1)
	{
		if (l == r)
		{
			cnt[o] += qy;
			if (cnt[o]) rval[o] = minv[o] = sumv[o] = a[qx];
			else minv[o] = sumv[o] = 0, rval[o] = INF;
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	LL query(int l, int r, int o = 1)
	{
		if (minv[o] >= 0)
		{
			return 0;
		}
		if (cnt[o] == 0)
		{
			return 0;
		}
		if (qx == 0) return 0;
		if (rval[o] <= 0 && cnt[o] <= qx)
		{
			qx -= cnt[o];
			return sumv[o];
		}
		int mid = (l + r) / 2;
		LL ret = 0;
		ret += query(l, mid, o << 1);
		ret += query(mid + 1, r, o << 1 | 1);
		return ret;
	}
} st;
LL lsum[N];
LL solve(int n, int len, int k)
{
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++) a[i] = -a[i];
	for (int i = 1; i <= n; i++)
	{
		lsum[i] = a[i] + lsum[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		vp.emplace_back(a[i], i);
	}
	sort(vp.begin(), vp.end());
	st.init();
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos = lower_bound(vp.begin(), vp.end(), make_pair(a[i], i)) - vp.begin() + 1;
		st.set(pos, pos, i, 1);
		st.add(1, n);
		if (i > len)
		{
			int pos2 = lower_bound(vp.begin(), vp.end(), make_pair(a[i - len], i - len)) - vp.begin() + 1;
			st.set(pos2, pos2, i - len, -1);
			st.add(1, n);
		}
		if (i >= len)
		{
			st.set(1, n, k);
			auto res = st.query(1, n);
			ans = max(ans, lsum[i] - lsum[i - len] - 2 * res);
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, len;
	cin >> n >> len;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int k;
	cin >> k;
	cout << max(solve(n, len, k), solve(n, len, k)) << endl;
	return 0;
}