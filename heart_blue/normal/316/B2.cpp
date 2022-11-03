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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;
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
int dp[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0) continue;
		if (uf.Find(a[i]) != uf.Find(i))
			uf.Union(a[i], i);
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) != i) continue;
		if (uf.Find(i) == uf.Find(x)) continue;
		int sz = uf.treesize(i);
		for (int j = n; j >= sz; j--)
			dp[j] |= dp[j - sz];
	}
	int cnt = 0;
	while (x)
	{
		cnt++;
		x = a[x];
	}
	for (int i = 0; i <= n; i++)
	{
		if (dp[i])
			printf("%d\n", cnt + i);
	}
	return 0;
}