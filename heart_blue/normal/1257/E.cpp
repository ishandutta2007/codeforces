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
const int N = 2e5 + 10;
class SegmentTree
{
public:
	int minv[N * 4];
	int addv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 0)
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
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return minv[o];
		}
		pushdown(o);
		int mid = (l + r) / 2;
		int ret = INF;
		if (ql <= mid) ret = min(ret, query(l, mid, o << 1));
		if (mid < qr) ret = min(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int sum[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k1, k2, k3;
	scanf("%d%d%d", &k1, &k2, &k3);
	int n = k1 + k2 + k3;
	int x;
	for (int i = 1; i <= k1; i++) scanf("%d", &x), flag[x] = 1;
	for (int i = 1; i <= k2; i++) scanf("%d", &x), flag[x] = 2;
	for (int i = 1; i <= k3; i++) scanf("%d", &x), flag[x] = 3;
	for (int i = n; i >= 1; i--)
	{
		sum[i] = sum[i + 1] + (flag[i] != 3);
	}
	int ans = n - max({ k1,k2,k3 });
	int tot1 = 0;
	int tot2 = 0;
	int tot3 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 1) tot1++;
		if (flag[i] == 2) tot2++;
		if (flag[i] == 3) tot3++;
		ans = min({ ans,k2 + tot3 + k1 - tot1,k1 + k2 + tot3 - tot2 });
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 3)
		{
			st.set(1, n, 1);
			st.add(1, n);
		}
		if (flag[i] == 1)
		{
			st.set(1, i, 1);
			st.add(1, n);
		}
		if (flag[i] == 2)
		{
			if (i < n)
			{
				st.set(i + 1, n, 1);
				st.add(1, n);
			}
		}
		st.set(1, i);
		ans = min(ans, st.query(1, n) + sum[i + 1]);
	}
	printf("%d\n", ans);
	return 0;
}