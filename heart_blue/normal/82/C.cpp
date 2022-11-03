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
const int N = 5e3 + 10;
typedef pair<int, int> Node;
priority_queue<Node, vector<Node>, greater<Node>> pq[N];
vector<pair<int, int>> v[N];
int cur = 0;
int ans[N];
int sz[N];
void dfs(int x, int fa = 0)
{
	sz[x] = 0;
	for (auto& p : v[x])
	{
		int y, w;
		tie(y, w) = p;
		if (y == fa) continue;
		while (w-- && !pq[y].empty())
		{
			auto p = pq[y].top();
			pq[y].pop();
			if (x == 1) ans[p.second] = cur;
			else pq[x].emplace(p);
			sz[y]--;
		}
		if (sz[y])
			dfs(y, x);
		sz[x] += sz[y];
	}
	sz[x] += pq[x].size();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sz[i] = INF;
		pq[i].emplace(x, i);
	}
	pq[1].pop();
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		v[x].emplace_back(y, w);
		v[y].emplace_back(x, w);
	}
	while (sz[1])
	{
		cur++;
		dfs(1);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}