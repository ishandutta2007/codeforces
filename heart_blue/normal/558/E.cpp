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
const int N = 1e5 + 10;
inline pair<int, int> operator + (const pair<int, int> &p1, const pair<int, int> &p2)
{
	return make_pair(p1.first + p2.first, p1.second + p2.second);
}
class SegmentTree
{
public:
	int ql, qr, qx, qo;
	int cnt[N * 4][2];
	int setv[N * 4];
	inline void set(int l, int r, int x, int o = 0)
	{
		ql = l, qr = r, qx = x, qo = o;
	}
	inline void maintain(int o)
	{
		cnt[o][0] = cnt[o << 1][0] + cnt[o << 1 | 1][0];
		cnt[o][1] = cnt[o << 1][1] + cnt[o << 1 | 1][1];
	}
	inline pair<int, int> getans(int l1, int r1, int l2, int r2, int cnt[2], int o)
	{
		int c[2] = { cnt[0], cnt[1] };
		c[o ^ 1] -= l1 - l2;
		c[o] -= max(0, -c[o ^ 1]);
		c[o ^ 1] = max(c[o ^ 1], 0);
		c[o] -= r2 - r1;
		c[o ^ 1] -= max(0, -c[o]);
		c[o] = max(0, c[o]);
		return make_pair(c[0], c[1]);
	}

	inline void pushdown(int l, int r, int o)
	{
		if (setv[o] != -1)
		{
			int mid = (l + r) >> 1;
			int son1 = mid - l + 1;
			int son2 = (r - l + 1) - son1;
			int x = setv[o] ^ 1;
			setv[o << 1] = setv[o << 1 | 1] = setv[o];
			tie(cnt[o << 1][0], cnt[o << 1][1]) = getans(l, mid, l, r, cnt[o], setv[o]);
			tie(cnt[o << 1 | 1][0], cnt[o << 1 | 1][1]) = getans(mid + 1, r, l, r, cnt[o], setv[o]);
			setv[o] = -1;
		}
	}
	void update1(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = 0;
			cnt[o][qx] = r - l + 1;
			cnt[o][qx ^ 1] = 0;
			return;
		}
		setv[o] = -1;
		pushdown(l, r, o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update1(l, mid, o << 1);
		if (qr > mid) update1(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	void update2(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = qo;
			int c[2] = { qx, qr - ql + 1 - qx };
			tie(cnt[o][0], cnt[o][1]) = getans(l, r, ql, qr, c, qo);
			return;
		}
		pushdown(l, r, o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update2(l, mid, o << 1);
		if (qr > mid) update2(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	pair<int, int> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return make_pair(cnt[o][0], cnt[o][1]);
		}
		pushdown(l, r, o);
		int mid = (l + r) >> 1;
		pair<int, int> ret = { 0, 0 };
		if (ql <= mid) ret = ret + query(l, mid, o << 1);
		if (qr > mid) ret = ret + query(mid + 1, r, o << 1 | 1);
		maintain(o);
		return ret;
	}
}st;
char s[N];
char ans[N];
vector<tuple<int, int, int>> qr;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	memset(ans, 'z', sizeof(ans));
	ans[n + 1] = 0;
	while (q--)
	{
		int l, r, o;
		scanf("%d%d%d", &l, &r, &o);
		qr.push_back(make_tuple(l, r, o));
	}
	for (char c = 'a'; c < 'z'; c++)
	{
		for (int i = 1; i <= n; i++)
		{
			st.set(i, i, s[i] > c);
			st.update1(1, n);
		}
		for (auto &p : qr)
		{
			int l, r, o;
			tie(l, r, o) = p;
			st.set(l, r, o);
			int x = st.query(1, n).first;
			st.set(l, r, x, o);
			st.update2(1, n);
		}
		for (int i = 1; i <= n; i++)
		{
			if (ans[i] < 'z') continue;
			st.set(i, i, i);
			if (st.query(1, n).first == 1) ans[i] = c;
		}
	}
	puts(ans + 1);
	return 0;
}