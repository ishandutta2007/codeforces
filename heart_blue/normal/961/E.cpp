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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
class SegmentTree
{
public:
	vector<int> v[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x)
	{
		ql = l;
		qr = r;
		qx = x;
	}
	void build(int l, int r, int o = 1)
	{
		v[o].resize(r - l + 1);
		for (int i = 0; i < v[o].size(); i++) v[o][i] = a[l + i];
		sort(v[o].begin(), v[o].end());
		if (l == r)
		{
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return v[o].end() - lower_bound(v[o].begin(), v[o].end(), qx);
		}
		int mid = (l + r) >> 1;
		int ret = 0;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (mid < qr) ret += query(mid + 1, r, o << 1 | 1);
		return ret;
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	st.build(1, n);
	LL ans = 0;
	for (int i = 1; i < n; i++)
	{
		int l = i + 1;
		int r = min(n, a[i]);
		if (r < l)
		{
			continue;
		}
		st.set(l, r, i);
		ans += st.query(1, n);
	}
	printf("%lld\n", ans);
	return 0;
}