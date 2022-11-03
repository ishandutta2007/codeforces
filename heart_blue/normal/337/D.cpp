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
const int N = 1e5 + 10;
vector<int> v[N];
int flag[N];
int maxv[N];
int evil[N];
int vis[N];
int dis[N];
void init(int n)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() == 1) q.push(i), vis[i] = 1;
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (evil[x]) continue;
		flag[x] = 1;
		for (auto &y : v[x])
		{
			if (vis[y])
			{
				q.push(y);
				vis[y] = 1;
			}
		}
	}
}
void dfs1(int x, int fa = -1)
{
	dis[x] = 0;
	if (fa != -1) dis[x] = dis[fa] + 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x);
	}
}

int check(int n, int rt)
{
	dfs1(rt);
	int k = rt;
	for (int i = 1; i <= n; i++)
	{
		if (evil[i] && dis[k] < dis[i]) k = i;
		maxv[i] = max(maxv[i], dis[i]);
	}
	return k;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, d;
	int x;
	cin >> n >> m >> d;
	MEM(flag, 0);
	MEM(evil, 0);
	MEM(vis, 0);
	while (m--)
	{
		cin >> x;
		evil[x] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	init(n);
	int rt = x;
	rt = check(n, rt);
	rt = check(n, rt);
	rt = check(n, rt);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (maxv[i] <= d) ans++;
	}
	cout << ans << endl;

	return 0;
}