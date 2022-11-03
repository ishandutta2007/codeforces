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
const int N = 2e5 + 10;
vector<pair<int, int>> vp[N];
int pos[N];
vector<int> v1, v2;
int vis[N];
void dfs(int x, int fa = -1)
{
	if (vis[x]) return;
	vis[x] = 1;
	v2.push_back(x);
	for (auto& p : vp[x])
	{
		if (p.second == fa) continue;
		dfs(p.second, x);
	}
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
		vp[x].push_back({ 0,y });
		vp[y].push_back({ 0,x });
	}
	int rt = 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v1.push_back(x);
		pos[x] = i;
		if (rt == 0) rt = x;
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto& p : vp[i])
		{
			p.first = pos[p.second];
		}
		sort(vp[i].begin(), vp[i].end());
	}
	queue<int> q;
	q.push(rt);
	vis[rt] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		v2.push_back(x);
		for (auto& p : vp[x])
		{
			if (vis[p.second]) continue;
			vis[p.second] = 1;
			q.push(p.second);
		}
	}
	if (v1 == v2) puts("Yes");
	else puts("No");
	return 0;
}