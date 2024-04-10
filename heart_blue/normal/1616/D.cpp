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
const int N = 5e4 + 10;
class SegmentTree
{
public:
	int maxv[N * 4];
	int addv[N * 4];
	int ql, qr, qx;
	void init()
	{
		MEM(maxv, 0);
		MEM(addv, 0);
	}
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	inline void pushdown(int o)
	{
		if (addv[o])
		{
			int x = addv[o];
			int l = o << 1;
			int r = o << 1 | 1;
			addv[l] += x;
			addv[r] += x;
			maxv[l] += x;
			maxv[r] += x;
			addv[o] = 0;
		}
	}
	inline void maintain(int o)
	{
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	void add(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			maxv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) / 2;
		if (ql <= mid) add(l, mid, o << 1);
		if (mid < qr) add(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		pushdown(o);
		int ret1 = 0, ret2 = 0;
		int mid = (l + r) / 2;
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		return max(ret1, ret2);
	}
} st;
int a[N];
LL sum[N];
int last[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int key;
		scanf("%d", &key);
		for (int i = 1; i <= n; i++)
			a[i] -= key;
		st.init();
		vector<int> v;
		int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			sum[i] = a[i] + sum[i - 1];
			last[i] = 1;
			st.set(0, i - 1, 1);
			st.add(0, n);
			if (i >= 2)
			{
				while (!v.empty() && sum[i - 2] >= sum[v.back()]) v.pop_back();
				v.push_back(i - 2);
				int l = 0, r = v.size() - 1;
				last[i] = 1;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (sum[i] - sum[v[mid]] < 0) last[i] = v[mid] + 2, l = mid + 1;
					else r = mid - 1;
				}
				last[i] = max(last[i - 1], last[i]);
			}
			if (last[i] == 1)
			{
				ans = i;
				st.set(i, i, i);
				st.add(0, n);
			}
			else
			{
				st.set(last[i] - 2, i - 2);
				int ret = st.query(0, n) - 1;
				st.set(i, i, ret);
				st.add(0, n);
				ans = max(ans, ret);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}