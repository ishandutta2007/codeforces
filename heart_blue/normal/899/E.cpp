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
class UnionFind
{
public:
	int p[N];
	int l[N];
	int r[N];
	int sz[N];
	int R[N];
	void init(int n = N)
	{
		for (int i = 0; i < n; i++) p[i] = -1;
		for (int i = 0; i < n; i++) l[i] = i;
		for (int i = 0; i < n; i++) r[i] = i;
		for (int i = 0; i < n; i++) sz[i] = 1;
		for (int i = 0; i < n; i++) R[i] = i;
	}
	int getTrueR(int x)
	{
		return R[Find(x)];
	}
	void setTrueR(int x, int val)
	{
		int px = Find(x);
		R[px] = val;
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int tmp = p[x];
			p[x] = s;
			x = tmp;
		}
		return x;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		l[px] = min(l[px], l[py]);
		r[px] = max(r[px], r[py]);
		R[px] = max(R[px], R[py]);
		sz[px] += sz[py];
		p[px] += p[py];
		p[py] = px;
	}
	void setSize(int x, int val)
	{
		int px = Find(x);
		sz[px] = val;
	}
	int getSize(int x)
	{
		int px = Find(x);
		return sz[px];
	}
	int getLeft(int x)
	{
		return l[Find(x)];
	}
	int getRight(int x)
	{
		return r[Find(x)];
	}
} uf;
class Node
{
public:
	int sz, pos;
	bool operator < (const Node node) const
	{
		if (sz != node.sz) return sz < node.sz;
		return pos > node.pos;

	}
};
priority_queue <Node> pq;
int flag[N];
int a[N];
int nex[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int key = 1;
	uf.init();
	cin >> n;
	a[0] = -1;
	a[n + 1] = -2;
	for (int i = 0; i <= n; i++)
	{
		nex[i] = i + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i > 1)
		{
			if (a[i] == a[i - 1]) uf.Union(i, i - 1);
		}
		if (a[i] != a[key])
		{
			pq.push({ i - key, key });
			key = i;
		}
	}
	pq.push({ n - key + 1, key });
	int ans = 0;
	while (!pq.empty())
	{
		auto node = pq.top();
		pq.pop();
		int pos = node.pos;
		if (flag[pos]) continue;
		//cout << "*" << ' ' << pos << ' ' << node.sz << endl;
		ans++;
		uf.setSize(pos, 0);
		uf.setTrueR(pos, 0);
		int l = uf.getLeft(pos), r = uf.getRight(pos);
		//cout << "**" << l << ' ' << r << ' ' << a[l] << endl;
		int o = l;
		while (o <= r && a[o] == a[pos])
		{
			flag[o] = 1;
			//cout << o << ' ';
			o = nex[o];
		}
		//cout << endl;
		int L = uf.getLeft(l - 1);
		int R = uf.getLeft(r + 1);
		nex[uf.getTrueR(L)] = r + 1;
		if (a[L] == a[R])
		{
			uf.Union(L, R);
			pq.push({ uf.getSize(L), L });
		}
		uf.Union(l, l - 1);
	}
	cout << ans << endl;
	return 0;
}