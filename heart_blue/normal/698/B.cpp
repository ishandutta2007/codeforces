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
const int N = 2e5 + 10;
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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	uf.init();
	vector<int> fa;
	vector<int> circle;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == a[i])
		{
			fa.push_back(i);
		}
		else
		{
			if (uf.Find(i) == uf.Find(a[i])) circle.push_back(i);
			else uf.Union(i, a[i]);
		}
	}
	int x = 0;
	int ans = 0;
	if (!fa.empty()) x = fa[0];
	else if (!circle.empty()) x = circle[0];
	for (auto &y : fa)
	{
		if (a[y] != x) ans++;
		a[y] = x;
	}
	for (auto &y : circle)
	{
		if (a[y] != x) ans++;
		a[y] = x;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}