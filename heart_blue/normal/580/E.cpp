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
const int N = 1e5 + 10;
const int MOD = 998244853;
const int K = 131;
LL p[N];
LL kp[N];
char str[N];
class SegmentTree
{
public:
	pair<LL, int> sumv[N * 4];
	int setv[N * 4];
	int ql, qr, qx;
	SegmentTree()
	{
		MEM(setv, -1);
	}
	void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	pair<LL, int> add(pair<LL, int>& p1, pair<LL, int>& p2)
	{
		if (p1.second == -1) return p2;
		if (p2.second == -1) return p1;
		return make_pair((p1.first * p[p2.second + 1] + p2.first) % MOD,
			p1.second + p2.second + 1);
	}
	void maintain(int l, int r, int o)
	{
		sumv[o] = add(sumv[o << 1], sumv[o << 1 | 1]);
	}
	void build(int l, int r, int o = 1)
	{
		if (l == r)
		{
			sumv[o] = { LL(str[l] - '0'),0 };
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		maintain(l, r, o);
	}
	void pushdown(int l, int r, int o = 1)
	{
		if (setv[o] != -1)
		{
			int mid = (l + r) / 2;
			int len1 = mid - l;
			int len2 = r - mid - 1;
			setv[o << 1] = setv[o << 1 | 1] = setv[o];
			sumv[o << 1] = make_pair(kp[len1] * setv[o] % MOD, len1);
			sumv[o << 1 | 1] = make_pair(kp[len2] * setv[o] % MOD, len2);
		}
		setv[o] = -1;
	}
	pair<LL, int> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return sumv[o];
		}
		int mid = (l + r) / 2;
		pair<LL, int> ret1, ret2;
		ret1 = ret2 = { 0LL,-1 };
		pushdown(l, r, o);
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		return add(ret1, ret2);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = qx;
			sumv[o].first = kp[r - l] * setv[o] % MOD;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(l, r, o);
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(l, r, o);
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	p[0] = 1;
	for (int i = 1; i < N; i++) p[i] = p[i - 1] * K % MOD;
	kp[0] = 1;
	for (int i = 1; i < N; i++) kp[i] = (kp[i - 1] * K + 1) % MOD;
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", str + 1);
	st.build(1, n);
	m += k;
	while (m--)
	{
		int op, l, r, d;
		scanf("%d%d%d%d", &op, &l, &r, &d);
		if (op == 1)
		{
			st.set(l, r, d);
			st.update(1, n);
		}
		else
		{
			if (r - l + 1 == d)
			{
				puts("YES");
				continue;
			}
			st.set(l, r - d);
			LL ret1 = st.query(1, n).first;
			st.set(l + d, r);
			LL ret2 = st.query(1, n).first;
			if (ret1 == ret2) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}