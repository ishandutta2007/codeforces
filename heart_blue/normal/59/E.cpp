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
const int N = 3e3 + 10;
map<pair<int, int>, pair<int, int>> pre;
map<pair<int, int>, int> dis;
map<pair<int, int>, int> key;
map<tuple<int, int, int>, int> inv;
vector<int> v[N];
void solve(int n)
{
	dis[{-1, 1}] = 0;
	queue<pair<int, int>> q;
	q.emplace(-1, 1);
	while (!q.empty())
	{
		int o, x;
		tie(o, x) = q.front();
		q.pop();
		if (x == n)
		{
			vector<int> ans;
			while (pre.count({ o,x }))
			{
				ans.push_back(x);
				tie(o, x) = pre[{o, x}];
			}
			ans.push_back(x);
			reverse(ans.begin(), ans.end());
			printf("%d\n", ans.size() - 1);
			for (int i = 0; i < ans.size(); i++)
				printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
			return;
		}
		for (auto& y : v[x])
		{
			if (inv.count(make_tuple(o, x, y))) continue;
			int oo = -1;
			if (key.count({ x,y }))
				oo = key[{x, y}];
			if (!dis.count({ oo,y }))
			{
				dis[{oo, y}] = dis[{o, x}] + 1;
				pre[{oo, y}] = { o,x };
				q.emplace(oo, y);
			}
		}
	}
	puts("-1");
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= k; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		key[{a, b}] = a;
		inv[{a, b, c}] = 1;
	}
	solve(n);
	return 0;
}