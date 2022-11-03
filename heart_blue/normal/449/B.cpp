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
typedef pair<LL, int> Node;
priority_queue<Node, vector<Node>, greater<Node>> pq1, pq2;
vector<pair<int, LL>> vp[N];
int vis[N];
LL dis[N];
int getans(int s)
{
	MEM(vis, 0);
	pq2.push({ 0,s });
	MEM(dis, 0x3f);
	pq2.push({ INF*INF,0 });
	pq1.push({ INF*INF,0 });
	dis[s] = 0;
	int ans = 0;
	while (pq1.size() > 1 || pq2.size() > 1)
	{
		auto p1 = pq1.top();
		auto p2 = pq2.top();
		Node p;
		int flag = 0;
		if (p1.first < p2.first)
		{
			flag = 1;
			p = p1;
			pq1.pop();
		}
		else
		{
			p = p2;
			pq2.pop();
		}
		LL d;
		int x;
		tie(d, x) = p;
		if (vis[x]) continue;
		vis[x] = 1;
		dis[x] = d;
		ans += flag;
		for (auto &pp : vp[x])
		{
			int y;
			LL w;
			tie(y, w) = pp;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				pq2.push({ dis[y],y });
			}
		}
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		LL w;
		cin >> x >> y >> w;
		vp[x].push_back({ y,w });
		vp[y].push_back({ x,w });
	}
	for (int i = 1; i <= k; i++)
	{
		int x;
		LL w;
		cin >> x >> w;
		pq1.push({ w,x });
	}
	cout << k - getans(1) << endl;
	return 0;
}