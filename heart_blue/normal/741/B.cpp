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
const int N = 1e3 + 10;
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
int w[N];
int b[N];
int w1[N];
int b1[N];
int dp[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, tot;
	cin >> n >> m >> tot;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	uf.init();
	MEM(dp, 0x80);
	MEM(w1, 0);
	MEM(b1, 0);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (uf.Find(x) != uf.Find(y))
			uf.Union(x, y);
	}
	for (int i = 1; i <= n; i++)
	{
		int p = uf.Find(i);
		w1[p] += w[i];
		b1[p] += b[i];
		v[p].push_back(i);
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (v[i].empty()) continue;
		int p = i;
		for (int j = tot; j >= 0; j--)
		{
			if (j >= w1[p]) dp[j] = max(dp[j], dp[j - w1[p]] + b1[p]);
			for(auto &k : v[i])
			{
				if (j >= w[k]) dp[j] = max(dp[j], dp[j - w[k]] + b[k]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= tot; i++) ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}