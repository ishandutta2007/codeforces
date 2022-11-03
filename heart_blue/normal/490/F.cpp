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
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const int INF = 1e9 + 7;
const int N = 1e5 + 10;
int depth[N];
int flag[N];
int lson[N * 4];
int rson[N * 4];
int rt[N];
int a[N];
int fa[N];
int cnt[N];
int n;
vector<int> v[N];
struct Node
{
	int val, depth, x;
	Node(int val = 0, int depth = 0, int x = 0)
	{
		this->val = val;
		this->depth = depth;
		this->x = x;
	}
	inline void init()
	{
		val = depth = x = 0;
	}
	bool operator < (const Node& node) const
	{
		if (val != node.val) return val < node.val;
		if (depth != node.depth) return depth < node.depth;
		return x < node.x;
	}
	int operator +(const Node& node) const
	{
		return val + node.val;
	}
} lis[N * 4], lds[N * 4];
tuple<int, int, int> combine(Node node1, Node node2, int x = 0)
{
	if (x == 0)
	{
		if (node1.val == 0 || node2.val == 0) return make_tuple(0, 0, 0);
		else return make_tuple(node1.val + node2.val, node1.x, node2.x);
	}
	if (node1 < node2) swap(node1, node2);
	if (node1.val == 0 && node2.val == 0)
	{
		return make_tuple(1, depth[x], x);
	}
	if (node2.val == 0)
	{
		node2 = { 1,depth[x],x };
	}
	else
	{
		node2.val++;
	}
	return make_tuple(node1.val + node2.val, node1.x, node2.x);
}
tuple<int, int, int> ans;
class SegmentTree
{
	int k = 0;
	int ql, qr, qx, qy, qz;
public:
	void init()
	{
		k = 0;
	}
	inline int newnode()
	{
		k++;
		lson[k] = 0;
		rson[k] = 0;
		lis[k].init();
		lds[k].init();
		return k;
	}
	int merge(int x, int y)
	{
		if (!x || !y) return x | y;
		lis[x] = max(lis[x], lis[y]);
		lds[x] = max(lds[x], lds[y]);
		ans = max(ans, combine(lis[lson[x]], lds[rson[y]]));
		ans = max(ans, combine(lis[lson[y]], lds[rson[x]]));
		lson[x] = merge(lson[x], lson[y]);
		rson[x] = merge(rson[x], rson[y]);
		return x;
	}
	void set(int l, int r, int x = 0, int y = 0, int z = 0)
	{
		ql = l, qr = r, qx = x, qy = y, qz = z;
	}
	Node query(int l, int r, int& o, Node maxv[])
	{
		if (o == 0) return Node{ 0,0,0 };
		if (ql <= l && r <= qr)
		{
			return maxv[o];
		}
		Node ret1{ 0,0,0 }, ret2{ 0,0,0 };
		int mid = (l + r) / 2;
		if (ql <= mid) ret1 = query(l, mid, lson[o], maxv);
		if (mid < qr) ret2 = query(mid + 1, r, rson[o], maxv);
		return max(ret1, ret2);
	}
	void update(int l, int r, int& o, Node maxv[])
	{
		if (o == 0) o = newnode();
		maxv[o] = max(maxv[o], Node{ qx,qy,qz });
		if (ql <= l && r <= qr)
		{
			return;
		}
		int mid = (l + r) / 2;
		if (ql <= mid) update(l, mid, lson[o], maxv);
		if (mid < qr) update(mid + 1, r, rson[o], maxv);
		//maxv[o] = max(maxv[lson[o]], maxv[rson[o]]);
	}
} st;
void dfs(int x, int p = 0)
{
	flag[x] = 1;
	depth[x] = depth[p] + 1;
	fa[x] = p;
	Node res1, res2;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		if (flag[y]) continue;
		dfs(y, x);
	}
	for (auto& y : v[x])
	{
		if (y == p) continue;
		Node t1, t2;
		if (a[x] > 1)
		{
			st.set(1, a[x] - 1);
			t1 = st.query(1, n, rt[y], lis);
		}
		if (a[x] < n)
		{
			st.set(a[x] + 1, n);
			t2 = st.query(1, n, rt[y], lds);
		}
		ans = max(ans, combine(res1, t2, x));
		ans = max(ans, combine(t1, res2, x));
		res1 = max(res1, t1);
		res2 = max(res2, t2);
		rt[x] = st.merge(rt[x], rt[y]);
	}
	if (res1.val++ == 0)
		res1.depth = depth[x], res1.x = x;
	st.set(a[x], a[x], res1.val, res1.depth, res1.x);
	st.update(1, n, rt[x], lis);
	if (res2.val++ == 0)
		res2.depth = depth[x], res2.x = x;
	st.set(a[x], a[x], res2.val, res2.depth, res2.x);
	st.update(1, n, rt[x], lds);
}
bool getpath(int x, int key, vector<int>& vp, int p = 0)
{
	vp.push_back(x);
	if (x == key) return true;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		if (getpath(y, key, vp, x))
			return true;
	}
	vp.pop_back();
	return false;
}
void init()
{
	MEM(rt, 0);
	MEM(flag, 0);
	st.init();
	ans = make_tuple(0, 0, 0);
}
void refrain(int n)
{
	vector<int> v(a + 1, a + n + 1);
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		//cerr << i << ' ' << a[i] << endl;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	refrain(n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		//printf("%d(%d) %d(%d)\n", x, a[x], y, a[y]);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init();
	dfs(1);
	vector<int> path;
	int kx, ky;
	int ret;
	tie(ret, kx, ky) = ans;
	printf("%d\n", ret);
	return 0;
	getpath(kx, ky, path);
	for (int i = 0; i <= n; i++)
	{
		int l = INF, r = -1;
		for (int j = 0; j < path.size(); j++)
		{
			if (cnt[path[j]] == i)
			{
				l = min(l, j);
				r = max(r, j);
			}
		}
		if (l > r) break;
		init();
		int x = path[(l + r) / 2];
		ans = make_tuple(1, 1, x);
		flag[x] = 1;
		for (auto& y : v[x])
		{
			dfs(y);
		}
		int res, kx, ky;
		tie(res, kx, ky) = ans;
		ret = min(ret, res);
		vector<int> vp;
		getpath(kx, ky, vp);
		for (auto& x : vp)
		{
			cnt[x]++;
		}
	}
	printf("%d\n", ret);
	return 0;
}