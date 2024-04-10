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
const int N = 2e5 + 10;
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int t = p[x];
			p[x] = s;
			x = t;
		}
		return s;
	}
	void Union(int x, int y)
	{
		if (Find(x) == Find(y)) return;
		int px = Find(x);
		int py = Find(y);
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	uf.init();
	while (m--)
	{
		int x, y, o;
		cin >> x >> y >> o;
		if (o == 0)
		{
			uf.Union(x * 2 + 1, y * 2);
			uf.Union(x * 2, y * 2 + 1);
		}
		else
		{
			uf.Union(x * 2, y * 2);
			uf.Union(x * 2 + 1, y * 2 + 1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i * 2) == uf.Find(i * 2 + 1))
			puts("Impossible"), exit(0);
	}
	MEM(flag, -1);
	for (int i = 2; i <= n * 2 + 1; i++)
	{
		int p = uf.Find(i);
		if (flag[p] != -1) continue;
		flag[p] = 1;
		flag[p ^ 1] = 0;
	}
	vector<int> ans;
	for (int i = 2; i <= n * 2; i += 2)
	{
		if (flag[uf.Find(i)] == 1)
			ans.push_back(i / 2);
	}
	cout << ans.size() << endl;
	for (auto& x : ans) cout << x << ' ';
	return 0;
}