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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<pair<int, int>> vp[N];
LL dis[N];
int vis[N];
int pre[N];
priority_queue<pair<LL, int>,vector<pair<LL,int>>,greater<pair<LL,int>>> pq;
void dijkstra(int n)
{
	MEM(dis, 0x1f);
	MEM(vis, 0);
	MEM(pre, -1);
	dis[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty())
	{
		int x;
		LL d;
		tie(d, x) = pq.top();
		pq.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto &p : vp[x])
		{
			int y, w;
			tie(y, w) = p;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				pre[y] = x;
				pq.push({ dis[y],y });
			}
		}
	}
	if (pre[n] == -1)
	{
		cout << -1 << endl;
		return;
	}
	int o = n;
	vector<int> v;
	while (o != -1)
	{
		v.push_back(o);
		o = pre[o];
	}
	reverse(v.begin(), v.end());
	for (auto &x : v) cout << x << ' ';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		vp[x].push_back({ y,w });
		vp[y].push_back({ x,w });
	}
	dijkstra(n);
	return 0;
}