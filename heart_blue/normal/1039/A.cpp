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
LL a[N];
int x[N];
int cnt[N];
int flag[N];
LL L[N], R[N];
LL ans[N];
LL minv[N];
class SegmentTree
{
public:
	int minv[N * 4];
	int addv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
	}
	void build(int l, int r, int o = 1)
	{
		if (l > r) return;
		if (l == r)
		{
			minv[o] = cnt[o];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
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
	void maintain(int o)
	{
		minv[o] = min(minv[o << 1], minv[o << 1 | 1]);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			minv[o] -= qx;
			addv[o] -= qx;
			return;
		}
		pushdown(o);
		int mid = (l + r) >> 1;
		if (ql <= l) update(l, mid, o << 1);
		if (r < qr) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	LL t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];

	}
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		if (x[i] < i)
		{
			puts("No");
			return 0;
		}
		if (x[i - 1] > x[i])
		{
			puts("No");
			return 0;
		}
		cnt[x[i]]++;
	}
	st.build(1, n);
	for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
	LL l = 1;
	int now = 0;
	for (int i = 1; i <= n; i++) {
		l = max(l, a[i] + t);
		if (x[i] > i) {
			L[i]++;
			R[x[i]]--;
			if (x[i] != n) 
				minv[x[i]] = a[x[i] + 1] + t;
		}
		now += L[i] + R[i];
		if (now > 0 && i + 1 <= n)
		{
			l = max(l, a[i + 1] + t);
		}
		LL r = 3e18 + 1;
		if (minv[i]) r = minv[i];
		if (l >= r) {
			puts("No");
			return 0;
		}
		ans[i] = l++;
	}
	puts("Yes");
	for (int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
	return 0;
}