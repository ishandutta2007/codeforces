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
struct Node
{
	LL sum;
	int len;
	int lcnt, rcnt;
	int lval, rval;
};
class SegmentTree
{
public:
	int ql, qr, qx;
	Node node[N * 4];
	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	Node combine(Node& node1, Node& node2)
	{
		if (node1.sum < 0) return node2;
		if (node2.sum < 0) return node1;
		if (node1.rval <= node2.lval)
		{
			LL sum = node1.sum + node2.sum + 1LL * node1.rcnt * node2.lcnt;
			int lcnt = node1.lcnt;
			int rcnt = node2.rcnt;
			if (node1.lcnt == node1.len) lcnt += node2.lcnt;
			if (node2.rcnt == node2.len) rcnt += node1.rcnt;
			return { sum,
				node1.len + node2.len,lcnt,rcnt,node1.lval,node2.rval };
		}
		else
		{
			return { node1.sum + node2.sum,
			node1.len + node2.len,
			node1.lcnt,
			node2.rcnt,
			node1.lval,
			node2.rval };
		}
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			node[o] = { 1LL,1,1,1,qx,qx };
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		node[o] = combine(node[o << 1], node[o << 1 | 1]);
	}
	Node query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return node[o];
		}
		int mid = (l + r) / 2;
		Node ret1, ret2;
		ret1.sum = ret2.sum = -1;
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		return combine(ret1, ret2);
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		st.set(i, i, x);
		st.update(1, n);
	}
	while (q--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)
		{
			st.set(x, x, y);
			st.update(1, n);
		}
		else
		{
			st.set(x, y);
			LL ans = st.query(1, n).sum;
			printf("%lld\n", ans);
		}
	}
	return 0;
}