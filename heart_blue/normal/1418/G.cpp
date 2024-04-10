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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 8e5 + 10;
class SegmentTree
{
public:
	struct Node
	{
		int minv;
		int cnt;
		int addv;
	} node[N];
	int ql, qr;
	int qx;
	void init(int l, int r, int o = 1)
	{
		node[o].cnt = r - l + 1;
		if (l == r) return;
		int mid = (l + r) / 2;
		init(l, mid, o << 1);
		init(mid + 1, r, o << 1 | 1);
	}
	void set(int l, int r, int x)
	{
		ql = l, qr = r, qx = x;
	}
	void add(int& x, int y)
	{
		x += y;
		if (x >= INF) x = INF;
	}
	inline void pushdown(int l, int r, int o)
	{
		if (node[o].addv)
		{
			add(node[o << 1].addv, node[o].addv);
			add(node[o << 1].minv, node[o].addv);
			add(node[o << 1 | 1].addv, node[o].addv);
			add(node[o << 1 | 1].minv, node[o].addv);
			node[o].addv = 0;
		}
	}
	inline void maintain(Node& node, Node& node1, Node& node2)
	{
		if (node1.minv < node2.minv) node.minv = node1.minv, node.cnt = node1.cnt;
		else if (node1.minv > node2.minv) node.minv = node2.minv, node.cnt = node2.cnt;
		else node.minv = node2.minv, node.cnt = node1.cnt + node2.cnt;
	}
	void update(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			add(node[o].addv, qx);
			add(node[o].minv, qx);
			return;
		}
		pushdown(l, r, o);
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, o << 1);
		if (mid < qr) update(mid + 1, r, o << 1 | 1);
		maintain(node[o], node[o << 1], node[o << 1 | 1]);
	}
	Node query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return node[o];
		}
		Node res1, res2;
		res1.minv = INF;
		res2.minv = INF;
		pushdown(l, r, o);
		int mid = (l + r) / 2;
		if (ql <= mid) res1 = query(l, mid, o << 1);
		if (mid < qr) res2 = query(mid + 1, r, o << 1 | 1);
		Node ret;
		maintain(ret, res1, res2);
		maintain(node[o], node[o << 1], node[o << 1 | 1]);
		return ret;
	}
} st[3];
vector<int> v[N];
pair<int, int> pos[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		pos[i] = make_pair((i - 1) / 3 + 1, (i - 1) % 3);
	}
	int len = n / 3 + 1;
	int cur = 0;
	LL ans = 0;
	st[0].init(1, len);
	st[1].init(1, len);
	st[2].init(1, len);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v[x].insert(v[x].begin(), i);
		if (i > 2)
		{
			int p, o;
			tie(p, o) = pos[i - 2];
			st[o].set(1, p, 1);
			st[o].update(1, len);
			st[o].set(1, p, 1);
		}
		if (v[x].size() > 4) v[x].pop_back();
		if (v[x].size() == 4)
		{
			int y = v[x].back();
			for (int j = 0; j < 3; j++)
			{
				if (y - j <= 0) break;
				int p, o;
				tie(p, o) = pos[y - j];
				st[o].set(1, p, INF);
				st[o].update(1, len);
			}
		}
		if (v[x].size() < 3) continue;
		int l = 1;
		if (v[x].size() == 4) l = v[x].back() + 1;
		int r = v[x][2];
		for (int o1 = 0; o1 < 3; o1++)
		{
			for (int o2 = 0; o2 < 3; o2++)
			{
				if (l + o1 > r - o2) continue;
				if (pos[l + o1].second != pos[r - o2].second) continue;
				int o = pos[l + o1].second;
				int L = pos[l + o1].first;
				int R = pos[r - o2].first;
				st[o].set(L, R, -1);
				st[o].update(1, len);
			}
		}
		int p, o;
		tie(p, o) = pos[i - 2];
		auto res = st[o].query(1, len);
		if (res.minv == 0)
			ans += res.cnt;
	}
	printf("%lld\n", ans);
	return 0;
}