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
const int N = 2e5 + 10;
LL a[N];
priority_queue<int> pq;
class SegmentTree
{
public:
	LL minv[N * 4];
	LL addv[N * 4];
	int ql, qr, qx;
	inline void pushdown(int l, int r, int o)
	{
		if (addv[o])
		{
			addv[o << 1] += addv[o];
			addv[o << 1 | 1] += addv[o];
			minv[o << 1] -= addv[o];
			minv[o << 1 | 1] -= addv[o];
			addv[o] = 0;
		}
	}

	inline void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	void build(int l, int r, int o = 1)
	{
		if (l == r)
		{
			minv[o] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			minv[o] -= qx;
			if (minv[o] > 0)
			{
				addv[o] += qx;
				return;
			}
		}
		if (l == r)
		{
			pq.emplace(l);
			minv[o] = INF * INF;
			return;
		}
		pushdown(l, r, o);
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
} st;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if (a[i] == 0)
		{
			pq.emplace(i);
			a[i] = INF * INF;
		}
	}
	st.build(1, n);
	int cur = 1;
	while (!pq.empty())
	{
		int x = pq.top();
		pq.pop();
		ans[x] = cur;
		st.set(x, n, cur);
		st.update(1, n);
		cur++;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}