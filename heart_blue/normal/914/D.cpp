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
const int N = 5e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
class SegmentTree
{
public:
	int gcdv[N*4];
	int ql, qr, qx;
	int cnt = 0;
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
		cnt = 0;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			gcdv[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (qr > mid) update(mid + 1, r, o << 1 | 1);
		gcdv[o] = gcd(gcdv[o << 1], gcdv[o << 1 | 1]);
	}
	bool query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			if (gcdv[o] % qx == 0) return true;
		}
		if (l == r)
		{
			cnt++;
			return cnt <= 1;
		}
		int mid = (l + r) >> 1;
		if (ql <= mid)
		{
			if (!query(l, mid, o << 1)) return false;
		}
		if (mid < qr)
		{
			if (!query(mid + 1, r, o << 1|1)) return false;
		}
		return true;
	}
} st;
int readint() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9')c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	n = readint();
	for (int i = 1; i <= n; i++)
	{
		int x;
		x = readint();
		st.set(i, i, x);
		st.update(1, n);
	}
	int q;
	q = readint();
	while (q--)
	{
		int op;
		op = readint();
		if (op == 1)
		{
			int l, r, x;
			l = readint();
			r = readint();
			x = readint();
			st.set(l, r, x);
			if (st.query(1, n)) puts("YES");
			else puts("NO");
		}
		else
		{
			int pos, x;
			pos = readint();
			x = readint();
			st.set(pos, pos, x);
			st.update(1, n);
		}
	}
	return 0;
}