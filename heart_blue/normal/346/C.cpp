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
const int N = 1e6 + 10;
int maxv[N];
class SegmentTree
{
public:
	int minv[N * 4];
	int ql, qr, qx;
	SegmentTree()
	{
		MEM(minv, 0x3f);
	}
	void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			minv[o] = min(minv[o], qx);
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o = 1)
	{
		int ret = minv[o];
		if (l == r) return ret;
		int mid = (l + r) / 2;
		if (qx <= mid) ret = min(ret, query(l, mid, o << 1));
		else ret = min(ret, query(mid + 1, r, o << 1 | 1));
		return ret;
	}
} st;
int v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	sort(v + 1, v + n + 1);
	int a, b;
	scanf("%d%d", &a, &b);
	int len = a - b;
	fill(maxv, maxv + N, 2);
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == v[i - 1]) continue;
		int x = v[i];
		for (int j = (x - b % x) % x; j <= len; j += x)
		{
			maxv[j] = max(maxv[j], x);
		}
	}
	st.set(0, 0, 0);
	st.update(0, len);
	for (int i = 0; i < len; i++)
	{
		st.set(i, i, i);
		int val = st.query(0, len);
		st.set(i + 1, min(len, i + maxv[i] - 1), val + 1);
		st.update(0, len);
	}
	st.set(len, len, len);
	int ans = st.query(0, len);
	printf("%d\n", ans);
	return 0;
}