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
const int N = 2e5 + 10;
class SegmentTree
{
public:
	int sumv[N * 4];
	int setv[N * 4];
	int ql, qr, qx;
	void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	inline void pushdown(int l, int r, int o)
	{
		if (setv[o])
		{
			int lson = (r + l) / 2 - l + 1;
			int rson = r - l + 1 - lson;
			setv[o << 1] ^= 1;
			setv[o << 1 | 1] ^= 1;
			setv[o] = 0;
			sumv[o << 1] = lson - sumv[o << 1];
			sumv[o << 1 | 1] = rson - sumv[o << 1 | 1];
		}
	}
	inline void maintain(int o)
	{
		sumv[o] = sumv[o << 1] + sumv[o << 1 | 1];
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] ^= 1;
			sumv[o] = r - l + 1 - sumv[o];
			return;
		}
		pushdown(l, r, o);
		int mid = (l + r) >> 1;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(o);
	}
	int query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return sumv[o];
		}
		pushdown(l, r, o);
		int mid = (l + r) >> 1;
		int ret = 0;
		if (ql <= mid) ret += query(l, mid, o << 1);
		if (mid < qr) ret += query(mid + 1, r, o << 1 | 1);
		maintain(o);
		return ret;
	}
} st;
int in[N], out[N];
int cnt = 0;
vector<int> v[N];
void dfs(int x)
{
	in[x] = ++cnt;
	for (auto &y : v[x])
	{
		dfs(y);
	}
	out[x] = cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x)
		{
			st.set(in[i], in[i]);
			st.update(1, n);
		}
	}
	int q;
	scanf("%d", &q);
	char qr[10];
	int x;
	while (q--)
	{
		scanf("%s %d", qr, &x);
		if (qr[0] == 'g')
		{
			st.set(in[x], out[x]);
			printf("%d\n", st.query(1, n));
		}
		else
		{
			st.set(in[x], out[x]);
			st.update(1, n);
		}
	}
	return 0;
}