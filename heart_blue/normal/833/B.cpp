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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int dp[N];
class SegmentTree
{
public:
	int sumv[N * 4];
	int maxv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void maintain(int o)
	{
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	void pushdown(int o)
	{
		if (sumv[o])
		{
			sumv[o << 1] += sumv[o];
			sumv[o << 1 | 1] += sumv[o];
			maxv[o << 1] += sumv[o];
			maxv[o << 1 | 1] += sumv[o];
			sumv[o] = 0;
		}
	}
	void build(int l, int r, int o = 1)
	{
		sumv[o] = 0;
		if (l == r)
		{
			maxv[o] = dp[l - 1];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			sumv[o] += qx;
			maxv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
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
		pushdown(o);
		int mid = (l + r) >> 1;
		int ret = 0;
		if (ql <= mid) ret = max(ret, query(l, mid, o << 1));
		if (mid < qr) ret = max(ret, query(mid + 1, r, o << 1 | 1));
		maintain(o);
		return ret;
	}
} st;
int cur[N];
int pre[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = cur[a[i]];
		cur[a[i]] = i;
	}
	MEM(dp, 0);
	for (int o = 1; o <= k; o++)
	{
		st.build(1, n);
		MEM(dp, 0);
		for (int i = 1; i <= n; i++)
		{
			st.set(pre[i] + 1, i, 1);
			st.update(1, n);
			st.set(1, i);
			dp[i] = st.query(1, n);
			//cout << dp[i] << ' ';
		}
		//cout << endl;
	}
	printf("%d\n", dp[n]);
	return 0;
}