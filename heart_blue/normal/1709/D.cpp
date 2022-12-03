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
	int maxv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	void build(int l, int r, int o = 1)
	{
		if (l == r)
		{
			scanf("%d", &maxv[o]);
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		maxv[o] = max(maxv[o << 1], maxv[o << 1 | 1]);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		int mid = (l + r) / 2;
		int ret1 = 0, ret2 = 0;
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		return max(ret1, ret2);
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	st.build(1, m);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int x1, y1, x2, y2, k;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
		if ((x2 - x1) % k || (y2 - y1) % k)
		{
			puts("NO");
			continue;
		}
		st.set(min(y1, y2), max(y1, y2));
		int maxv = st.query(1, m);
		int key = n - (n % k - x1 % k + k) % k;
		if (maxv >= key) puts("NO");
		else puts("YES");
	}
	return 0;
}