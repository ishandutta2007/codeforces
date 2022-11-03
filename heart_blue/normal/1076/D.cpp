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
const int N = 3e5 + 10;
vector<tuple<int,int,int>> v[N];
pair<int, int> fa[N];
LL dis[N];
int vis[N];
int deg[N];
int ans[N];
void dijkstra()
{
	typedef pair<LL, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	MEM(dis, 0x3f);
	dis[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty())
	{
		LL d;
		int x;
		tie(d, x) = pq.top();
		pq.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto &p : v[x])
		{
			int y, w, o;
			tie(y, w, o) = p;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				pq.push({ dis[y],y });
				fa[y] = { x,o };
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		v[x].push_back({ y,w,i });
		v[y].push_back({ x,w,i });
	}
	dijkstra();
	for (int i = 2; i <= n; i++)
	{
		ans[fa[i].second] = 1;
		deg[fa[i].first] ++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0) q.push(i);
	}
	int cur = n - 1;
	while (!q.empty() && cur > k)
	{
		cur--;
		int x = q.front();
		q.pop();
		ans[fa[x].second] = 0;
		if (deg[fa[x].first]-- == 1)
		{
			q.push(fa[x].first);
		}
	}
	vector<int> res;
	for (int i = 2; i <= n; i++)
	{
		if (ans[fa[i].second])
			res.push_back(fa[i].second);
	}
	printf("%d\n", res.size());
	for (auto &x : res) printf("%d ", x);
	return 0;
}