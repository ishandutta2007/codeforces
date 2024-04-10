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
char str[N];
class SegmentTree
{
public:
	struct Node
	{
		int a, b;
		int lis, lds;
		inline void change()
		{
			swap(a, b);
			swap(lis, lds);
		}
	} sumv[N * 4];
	int setv[N * 4];
	int ql, qr, qx;
	inline void set(int l, int r, int x = 1)
	{
		ql = l, qr = r, qx = x;
	}
	inline Node add(Node& node1, Node& node2)
	{
		if (node1.a == -1) return node2;
		if (node2.a == -1) return node1;
		return Node{ node1.a + node2.a,
		node1.b + node2.b,
		max(node1.lis + node2.b,node1.a + node2.lis),
		max(node1.lds + node2.a,node1.b + node2.lds) };
	}
	inline void maintain(int l, int r, int o)
	{
		sumv[o] = add(sumv[o << 1], sumv[o << 1 | 1]);
	}
	inline void pushdown(int l, int r, int o)
	{
		if (setv[o])
		{
			setv[o << 1] ^= 1;
			setv[o << 1 | 1] ^= 1;
			sumv[o << 1].change();
			sumv[o << 1 | 1].change();
			setv[o] = 0;
		}
	}
	void build(int l, int r, int o = 1)
	{
		if (l == r)
		{
			if (str[l] == '4') sumv[o].a++;
			else sumv[o].b++;
			sumv[o].lis = sumv[o].lds = 1;
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		maintain(l, r, o);
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			setv[o] ^= 1;
			sumv[o].change();
			return;
		}
		int mid = (l + r) / 2;
		pushdown(l, r, o);
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(l, r, o);
	}
	Node query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return sumv[o];
		}
		int mid = (l + r) / 2;
		Node ret1, ret2;
		ret1 = ret2 = Node{ -1,-1,-1,-1 };
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		return add(ret1, ret2);
	}
} st;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);
	st.build(1, n);
	while (m--)
	{
		char op[10];
		scanf("%s", op);
		if (op[0] == 'c')
		{
			printf("%d\n", st.sumv[1].lis);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			st.set(l, r);
			st.update(1, n);
		}
	}
	return 0;
}