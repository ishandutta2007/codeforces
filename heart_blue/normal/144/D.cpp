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
const int N = 2e5 + 10;
deque<int> q;
LL dis[N];
int vis[N];
vector<pair<int, LL>> v[N];
tuple<int, int, LL> edge[N];
void spfa(int s)
{
	MEM(vis, 0);
	vis[s] = 1;
	q.push_back(s);
	MEM(dis, 0x3f);
	dis[s] = 0;
	q.push_back(s);
	while (!q.empty())
	{
		int x = q.front();
		q.pop_front();
		vis[x] = 0;
		for (auto &p : v[x])
		{
			int y, w;
			tie(y, w) = p;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				if (!vis[y])
				{
					vis[y] = 1;
					if (!q.empty() && dis[q.front()] >= dis[y]) q.push_front(y);
					else q.push_back(y);
				}
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		LL w;
		cin >> x >> y >> w;
		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
		edge[i] = { x,y,w };
	}
	spfa(s);
	int l;
	cin >> l;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		LL w;
		tie(u, v, w) = edge[i];
		LL d1 = l - dis[u];
		LL d2 = l - dis[v];
		if (d1 < d2) swap(d1, d2);
		if (d1 <= 0 || d2 >= w) continue;
		if (d2 <= 0)
		{
			if (d1 < w) ans++;
		}
		else
		{
			if (w == d1 + d2) ans++;
			else if (w > d1 + d2) ans += 2;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans += dis[i] == l;
	}
	cout << ans << endl;
	return 0;
}