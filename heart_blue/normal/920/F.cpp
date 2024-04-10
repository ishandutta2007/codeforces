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
const int M = 1e6 + 10;
int to[M];
void init()
{
	for (int i = 1; i < M; i++)
	{
		for (int j = i; j < M; j += i) to[j]++;
	}
}
class SegmentTree
{
public:
	LL sum[N * 4];
	int flag[N * 4];
	int ql, qr, qx;
	inline void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (l == r)
		{
			flag[o] = 0;
			sum[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		sum[o] = sum[o << 1] + sum[o << 1 | 1];
	}
	void update2(int l, int r, int o = 1)
	{
		if (flag[o]) return;
		if (l == r)
		{
			sum[o] = to[sum[o]];
			if (sum[o] < 3) flag[o] = 1;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update2(l, mid, o << 1);
		if (mid < qr) update2(mid + 1, r, o << 1 | 1);
		sum[o] = sum[o << 1] + sum[o << 1 | 1];
		flag[o] = flag[o << 1] & flag[o << 1 | 1];
	}
	LL query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return sum[o];
		}
		int mid = (l + r) >> 1;
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
	init();
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		st.set(i, i, x);
		st.update(1, n);
	}
	while (q--)
	{
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		st.set(l, r);
		if (op == 1)
		{
			st.update2(1, n);
		}
		else
		{
			printf("%lld\n", st.query(1, n));
		}
	}
	return 0;
}