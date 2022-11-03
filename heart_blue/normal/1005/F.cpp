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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> v;
vector<pair<int, int>> vp[N];
vector<int> key[N];
int dis[N];
char str[N];
int n, m;
void dfs(int cur, int& rest)
{
	if (rest == 0) return;
	if (cur == v.size())
	{
		rest--;
		puts(str);
		return;
	}
	int x = v[cur];
	for (auto& pos : key[x])
	{
		str[pos] = '1';
		dfs(cur + 1, rest);
		str[pos] = '0';
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(str, '0');
	scanf("%d%d", &n, &m);
	str[m] = 0;
	int k;
	scanf("%d", &k);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp[x].emplace_back(y, i);
		vp[y].emplace_back(x, i);
	}
	queue<int> q;
	MEM(dis, 0x3f);
	dis[1] = 0;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto [y, pos] : vp[x])
		{
			if (dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	sort(v.begin(), v.end(), [&](const int& x, const int& y) -> bool
		{
			return dis[x] < dis[y];
		});
	LL ans = 1;
	for (auto& x : v)
	{
		if (x == 1) continue;
		for (auto [y, pos] : vp[x])
		{
			if (dis[y] + 1 == dis[x])
			{
				key[x].push_back(pos);
			}
		}
		ans *= key[x].size();
		ans = min(ans, 1LL * k);
	}
	printf("%d\n", ans);
	int rest = ans;
	dfs(1, rest);
	return 0;
}