#pragma comment(linker, "/STACK:102400000,102400000") 
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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL sum[N];
class SegmentTree
{
public:
	vector<LL> v[N * 4];
	int ql, qr;
	LL qx;
	void set(int l, int r, LL x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	void build(int l, int r, int o = 1)
	{
		if (l > r) return;
		v[o].resize(r - l + 1);
		for (int i = l; i <= r; i++) v[o][i - l] = -sum[i];
		sort(v[o].begin(), v[o].end());
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return lower_bound(v[o].begin(), v[o].end(), qx) - v[o].begin();
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
	LL t;
	scanf("%d%lld", &n, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &sum[i]);
		sum[i] += sum[i - 1];
	}
	st.build(0, n);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		st.set(0, i - 1, t - sum[i]);
		ans += st.query(0, n);
	}
	printf("%lld\n", ans);
	return 0;
}