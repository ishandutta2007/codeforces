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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int low[N], dfn[N], cnt;
int son[N];
int n, m;
void tarjan(int x, int p = -1)
{
	son[x] = 0;
	low[x] = dfn[x] = cnt++;
	if (p != -1) son[x] ++;
	for (auto &y : v[x])
	{
		if (dfn[y]) low[x] = min(low[x], dfn[y]);
		else
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if (dfn[x] <= low[y])
			{
				son[x]++;
			}
		}
	}
}
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
vector<pair<int, int>> ans;
void check(int s, int t, int &tot1, int &tot2)
{
	
	int flag = 0;
	int key = 0;
	for (auto x : v[s])
	{
		if (x == t)
		{
			key = 1;
			continue;
		}
		if (uf.Find(x) != uf.Find(s))
		{
			if (tot1 == 0) break;
			uf.Union(x, s);
			ans.push_back({ x,s });
			flag = 1;
			tot1--;
		}
	}
	if (tot1 == 0 || tot2 == 0) return;
	if (uf.Find(s) == uf.Find(t)) return;
	if (key == 1)
	{
		uf.Union(s, t);
		ans.push_back({ s,t });
		tot1--;
		tot2--;
	}
}
bool solve(int s, int t, int ds, int dt)
{
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		if (i == t || i == s) continue;
		for (auto &j : v[i])
		{
			if (j == t || j == s) continue;
			if (uf.Find(i) != uf.Find(j))
			{
				uf.Union(i, j);
				ans.push_back({ i,j });
			}
		}
	}
	check(t, s, dt, ds);
	check(s, t, ds, dt);
	return uf.treesize(1) == n;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(son, 0);
	cnt = 1;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	
	int s, t, ds, dt;
	cin >> s >> t >> ds >> dt;
	if (son[s] > ds || son[t] > dt)
	{
		cout << "No" << endl;
		return 0;
	}
	
	if (solve(s,t,ds,dt) || solve(t,s,dt,ds)) 
	{
		cout << "Yes" << endl;
		for (auto &p : ans)
		{
			cout << p.first << ' ' << p.second << '\n';
		}
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}