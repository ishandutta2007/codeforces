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
int vis[N];
vector<pair<int, int>> vp;
set<int> s[N];
int deg[N];
int ans;
void init(int n, int k)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] < k)
			q.push(i), vis[i] = 1;
	}
	while (!q.empty())
	{
		ans--;
		int x = q.front();
		q.pop();
		for (auto iter = s[x].begin(); iter != s[x].end(); iter++)
		{
			int y = *iter;
			if (vis[y]) continue;
			s[y].erase(x);
			if (s[y].size() < k)
			{
				vis[y] = 1;
				q.push(y);
			}
		}
		s[x].clear();
	}
}
void solve(int x, int k)
{
	if (vis[x]) return;
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	while (!q.empty())
	{
		ans--;
		int x = q.front();
		q.pop();
		for (auto iter = s[x].begin(); iter != s[x].end(); iter++)
		{
			int y = *iter;
			if (vis[y]) continue;
			s[y].erase(x);
			if (s[y].size() < k)
			{
				vis[y] = 1;
				q.push(y);
			}
		}
		s[x].clear();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		vp.push_back({ x,y });
		s[x].insert(y);
		s[y].insert(x);
		deg[x]++;
		deg[y]++;
	}
	reverse(vp.begin(), vp.end());
	ans = n;
	init(n, k);
	vector<int> res;
	for (auto &p : vp)
	{
		res.push_back(ans);
		int x, y;
		tie(x, y) = p;
		if (vis[x] || vis[y]) continue;
		s[x].erase(y);
		s[y].erase(x);
		if (s[x].size() < k) solve(x, k);
		if (s[y].size() < k) solve(y, k);
	}
	reverse(res.begin(), res.end());
	for (auto &x : res)
		printf("%d\n", x);
	return 0;
}