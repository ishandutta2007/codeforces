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
public:
	int setv[N * 4];
	LL sumv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
	}
	void init()
	{
		MEM(setv, -1);
	}
	inline void pushdown(int l, int r, int o)
	{
		if (setv[o] != -1)
		{
			int mid = (l + r) / 2;
			LL lcnt = mid - l + 1;
			LL rcnt = r - mid;
			setv[o << 1] = setv[o << 1 | 1] = setv[o];
			sumv[o << 1] = lcnt * setv[o];
			sumv[o << 1 | 1] = rcnt * setv[o];
			setv[o] = -1;
		}
	}
	inline void maintain(int o)
	{
		sumv[o] = sumv[o << 1] + sumv[o << 1 | 1];
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = qx;
			sumv[o] = 1LL * qx * (r - l + 1);
			return;
		}
		int mid = (l + r) / 2;
		pushdown(l, r, o);
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	LL query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return sumv[o];
		}
		LL ret = 0;
		pushdown(l, r, o);
		int mid = (l + r) / 2;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (mid < qr) ret += query(mid + 1, r, o << 1 | 1);
		maintain(o);
		return ret;
	}
} st;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	str[n + 1] = '0';
	st.init();
	int cnt = 0;
	vector<pair<int, int>> vp;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == '1')
		{
			cnt++;
			ans += 1LL * cnt * (cnt + 1) / 2;
			while (!vp.empty() && vp.back().first < cnt)
			{
				vp.pop_back();
			}
			int l;
			if (vp.empty()) l = 1;
			else l = vp.back().second - cnt + 1;
			if (l <= i - cnt)
			{
				st.set(l, i - cnt, cnt);
				st.update(1, n);
			}
			st.set(1, n, 0);
			ans += st.query(1, n);
			if (str[i + 1] == '0')
			{
				for (int j = 0; j < cnt; j++)
				{
					st.set(i - j, i - j, j + 1);
					st.update(1, n);
				}
				vp.emplace_back(cnt, i);
			}
		}
		else
		{
			cnt = 0;
			st.set(1, n, 0);
			ans += st.query(1, n);
		}
	}
	printf("%lld\n", ans);
	return 0;
}