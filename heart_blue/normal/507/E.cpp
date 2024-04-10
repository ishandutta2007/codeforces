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
map<pair<int, int>, int> ms;
int vis[N];
pair<int, int> dis[N];
int pre[N];
vector<pair<int, int>> v[N];
vector<tuple<int, int, int>> vp,ans;
void solve()
{
	typedef pair<pair<int, int>, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	MEM(dis, 0x3f);
	dis[1] = { 0,0 };
	pq.push({ dis[1],1 });
	pre[1] = -1;
	while (!pq.empty())
	{
		int x = pq.top().second;
		pq.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto &p : v[x])
		{
			int y, o;
			tie(y, o) = p;
			auto tmp = make_pair(dis[x].first + 1, dis[x].second + o);
			if (dis[y] > tmp)
			{
				pre[y] = x;
				dis[y] = tmp;
				pq.push({ dis[y],y });
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, o;
		scanf("%d%d%d", &x, &y, &o);
		vp.push_back({ x, y ,o });
		v[x].push_back({ y,o ^ 1 });
		v[y].push_back({ x,o ^ 1 });
	}
	solve();
	int cur = n;
	while (pre[cur] != -1)
	{
		ms[{cur, pre[cur]}] = 1;
		ms[{pre[cur], cur}] = 1;
		cur = pre[cur];
	}
	for (auto &p : vp)
	{
		int x, y, o;
		tie(x, y, o) = p;
		if (ms.count({ x, y }))
		{
			if (o == 0) ans.push_back({ x,y,1 });
		}
		else
		{
			if (o == 1) ans.push_back({ x,y,0 });
		}
	}
	printf("%d\n", ans.size());
	for (auto &p : ans)
	{
		int x, y, o;
		tie(x, y, o) = p;
		printf("%d %d %d\n", x, y, o);
	}
	return 0;
}