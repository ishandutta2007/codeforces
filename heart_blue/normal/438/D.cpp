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
const int N = 3e5 + 10;
class SegmentTree
{
public:
	int maxv[N * 4];
	LL sumv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void maintain(int o)
	{
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
		sumv[o] = sumv[o << 1] + sumv[o << 1 | 1];
	}
	void update3(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			maxv[o] = sumv[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update3(l, mid, o << 1);
		if (qr > mid) update3(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	void update2(int l, int r, int o = 1)
	{
		if (maxv[o] < qx) return;
		if (l == r)
		{
			maxv[o] = sumv[o] = maxv[o] % qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update2(l, mid, o << 1);
		if (qr > mid) update2(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	LL query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return sumv[o];
		}
		LL ret = 0;
		int mid = (l + r) >> 1;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (qr > mid) ret += query(mid + 1, r, o << 1 | 1);
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		st.set(i, i, x);
		st.update3(1, n);
	}
	while (m--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			st.set(l, r);
			printf("%lld\n", st.query(1, n));
		}
		else if (op == 2)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			st.set(l, r, x);
			st.update2(1, n);
		}
		else
		{
			int k, x;
			scanf("%d%d", &k, &x);
			st.set(k, k, x);
			st.update3(1, n);
		}
	}
	return 0;
}