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
const int N = 1e3 + 10;
typedef pair<LL, int> Node;
vector<pair<int, int>> vp[N];
vector<int> v[N];
int n;
LL dis[N];
int vis[N];
int t[N];
int c[N];
LL inf;
void init(int s)
{
	MEM(dis, 0x3f);
	dis[s] = 0;
	MEM(vis, 0);
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({ dis[s],s });
	while (!pq.empty())
	{
		LL d;
		int x;
		tie(d, x) = pq.top();
		pq.pop();
		if (d > t[s]) break;
		if (vis[x]) continue;
		vis[x] = 1;
		v[s].push_back(x);
		for (auto &p : vp[x])
		{
			int y, w;
			tie(y, w) = p;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				pq.push({ dis[y],y });
			}
		}
	}
}
void solve(int s)
{
	MEM(dis, 0x3f);
	inf = dis[0];
	dis[s] = 0;
	MEM(vis, 0);
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({ dis[s],s });
	while (!pq.empty())
	{
		LL d;
		int x;
		tie(d, x) = pq.top();
		pq.pop();;
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto &y : v[x])
		{
			if (dis[y] > dis[x] + c[x])
			{
				dis[y] = dis[x] + c[x];
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
	cin >> n >> m;
	int a, b;
	cin >> a >> b;
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		vp[x].push_back({ y,w });
		vp[y].push_back({ x,w });
	}
	for (int i = 1; i <= n; i++) cin >> t[i] >> c[i];
	for (int i = 1; i <= n; i++) init(i);
	solve(a);
	if (dis[b] == inf) dis[b] = -1;
	cout << dis[b] << endl;
	return 0;
}