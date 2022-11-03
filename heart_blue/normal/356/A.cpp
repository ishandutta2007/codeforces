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
const int N = 3e5 + 10;
class SegmentTree
{
public:
	int setv[N*4];
	int ql, qr;
	int qx;
	SegmentTree()
	{
		init();
	}
	void init()
	{
		MEM(setv, -1);
	}
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;

	}
	void pushdown(int o)
	{
		if (setv[o] == -1) return;
		setv[o << 1] = setv[o];
		setv[o << 1 | 1] = setv[o];
		setv[o] = -1;
	}
	void setValue(int l, int r, int o)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] = qx;
			return;
		}
		int mid = (l + r) >> 1;
		pushdown(o);
		if (ql <= mid) setValue(l, mid, o << 1);
		if (qr > mid) setValue(mid + 1, r, o << 1 | 1);
	}
	int query(int l, int r, int o)
	{
		if (ql <= l && r <= qr)
		{
			if (setv[o] != -1) return setv[o];
		}
		int mid = (l + r) >> 1;
		pushdown(o);
		if (ql <= mid) return query(l, mid, o << 1);
		if (qr > mid) return query(mid + 1, r, o << 1 | 1);
	}
} st;
int l[N], r[N], x[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	st.init();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> l[i] >> r[i] >> x[i];
		l[i]--, r[i]--, x[i]--;
	}
	for (int i = m - 1; i >= 0; i--)
	{
		int s = 0;
		st.set(x[i], x[i]);
		if (i != m - 1) s = st.query(0, n - 1, 1);
		st.set(l[i], r[i], x[i] + 1);
		st.setValue(0, n - 1, 1);
		st.set(x[i], x[i], s);
		st.setValue(0, n - 1, 1);
	}
	for (int i = 0; i < n; i++)
	{
		st.set(i, i);
		cout << st.query(0, n - 1, 1) << ' ';
	}
	return 0;
}