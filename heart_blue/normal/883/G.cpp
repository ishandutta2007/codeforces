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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
struct Edge
{
	int y, o;
	int pos;
};
vector<Edge> vp[N];
int vis[N];
string ans1, ans2;
int k;
void dfs(int x, int fa = -1)
{
	if (vis[x]) return;
	vis[x] = 1;
	for (auto &e : vp[x])
	{
		int y = e.y, o = e.o;
		if (y == fa) continue;
		if (vis[y]) continue;
		if (o == 0) ans1[e.pos] = '+';
		else if(o == 1) ans1[e.pos] = '-';
		dfs(y, x);
	}
}
void solve1(int n, int s)
{
	ans1 = string(k, '+');
	MEM(vis, 0);
	dfs(s);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += vis[i];
	cout << cnt << endl;
	cout << ans1 << endl;
}
void solve2(int n, int s)
{
	queue<int> q;
	q.push(s);
	MEM(vis, 0);
	vis[s] = 1;
	ans2 = string(k, '+');
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto &e : vp[x])
		{
			int y = e.y, o = e.o;
			if (e.o == 2 && vis[y] == 0)
			{
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt += vis[i];
		if (vis[i]) continue;
		for (auto &e : vp[i])
		{
			if (e.o == 2) continue;
			if (e.o == 1) ans2[e.pos] = '-';
		}
	}
	cout << cnt << endl;
	cout << ans2 << endl;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s;
	cin >> n >> m >> s;
	k = 0;
	while (m--)
	{
		int o, x, y;
		cin >> o >> x >> y;
		if (o == 1)
		{
			vp[x].push_back({ y,2,0 });
		}
		else
		{
			vp[x].push_back({ y,0,k });
			vp[y].push_back({ x,1,k });
			k++;
		}
	}
	solve1(n, s);
	solve2(n, s);
	return 0;
}