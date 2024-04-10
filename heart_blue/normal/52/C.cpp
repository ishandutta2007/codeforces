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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class SegmentTree
{
public:
	LL addv[N * 4];
	LL minv[N * 4];
	int ql, qr, qx;
	void maintain(int o)
	{
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	void pushdown(int o)
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
	void set(int ql, int qr, int qx = 0)
	{
		this->ql = ql;
		this->qr = qr;
		this->qx = qx;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			addv[o] += qx;
			minv[o] += qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (qr > mid) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	LL query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return minv[o];
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		LL ret = INF*INF;
		if (ql <= mid) ret = min(ret, query(l, mid, o << 1));
		if (qr > mid) ret = min(ret, query(mid + 1, r, o << 1 | 1));
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
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		st.set(i, i, x);
		st.update(1, n);
	}
	int q;
	scanf("%d\n", &q);
	while (q--)
	{
		vector<int> v;
		scanf("%[^\n]", &str);
		getchar();
		int l, r, x;
		int ret = sscanf(str, "%d%d%d", &l, &r, &x);
		l++, r++;
		if (ret == 2)
		{
			if (l <= r)
			{
				st.set(l, r);
				printf("%lld\n", st.query(1, n));
			}
			else
			{
				LL ans1, ans2;
				st.set(l, n);
				ans1 = st.query(1, n);
				st.set(1, r);
				ans2 = st.query(1, n);
				printf("%lld\n", min(ans1, ans2));
			}
		}
		else
		{
			if (l <= r)
			{
				st.set(l, r, x);
				st.update(1, n);
			}
			else
			{
				st.set(l, n, x);
				st.update(1, n);
				st.set(1, r, x);
				st.update(1, n);
			}
		}
	}
	return 0;
}