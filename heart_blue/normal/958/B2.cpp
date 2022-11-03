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
const int K = 20;
int fa[N][K];
int depth[N];
vector<int> v[N];
int vis[N];  
void dfs(int x, int p = 0)
{
	depth[x] = depth[p] + 1;
	fa[x][0] = p;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
int init(int n)
{
	dfs(1);
	int rt = 1;
	for (int i = 1; i <= n; i++) if (depth[i] > depth[rt]) rt = i;
	dfs(rt);
	for (int o = 1; o < K; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i][o] = fa[fa[i][o - 1]][o - 1];
		}
	}
	return rt;
}
int moveup(int x)
{
	for (int i = 19; i >= 0; i--)
	{
		if (vis[fa[x][i]]) continue;
		x = fa[x][i];
	}
	return x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int rt = init(n);
	vis[rt] = vis[0] = 1;
	vector<int> ans;
	ans.push_back(1);
	int tot = 1;
	typedef pair<int, int> Node;
	priority_queue<Node> pq;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		pq.push({ depth[i],i });
	}
	while (!pq.empty())
	{
		int d, o;
		tie(d, o) = pq.top();
		pq.pop();
		if (vis[o]) continue;
		int x = moveup(o);
		if (depth[o] - depth[x] + 1 == d)
		{
			while (vis[o] == 0)
			{
				tot++;
				vis[o] = 1;
				o = fa[o][0];
			}
			ans.push_back(tot);
		}
		else
		{
			pq.push({ depth[o] - depth[x] + 1,o });
		}
	}
	while (ans.size() < n) ans.push_back(n);
	for (auto &x : ans) cout << x << ' ';
	return 0;
}