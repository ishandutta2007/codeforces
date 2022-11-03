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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
vector<int> v1, v2;
class UnionSet
{
public:
	int fa[N];
	void init()
	{
		MEM(fa, -1);
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
	}
	int Find(int x)
	{
		int root = x;
		while (fa[root] >= 0) root = fa[root];
		while (x != root)
		{
			int tmp = fa[x];
			fa[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
	}
} uf;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	v1.resize(n);
	for (auto &x : v1) cin >> x;
	v2 = v1;
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v2.size(); i++)
	{
		if (i + 1 != v2[i])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	uf.init();
	for (int i = 0; i < n; i++)
	{
		if (uf.Find(i + 1) != uf.Find(v1[i]))
			uf.Union(i + 1, v1[i]);
	}
	LL ans = 1;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) == i)
		{
			LL x = uf.treesize(i);
			if (x % 2 == 0) x /= 2;
			ans *= x / gcd(ans, x);
		}
	}
	cout << ans << endl;
	return 0;
}