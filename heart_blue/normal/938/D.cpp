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
const int N = 2e5 + 10;
LL dis[N];
vector<pair<int, LL>> vp[N];
int vis[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	typedef pair<LL, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	while (m--)
	{
		int x, y;
		LL w;
		cin >> x >> y >> w;
		vp[x].push_back({ y,w * 2 });
		vp[y].push_back({ x,w * 2 });
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> dis[i];
		pq.push({ dis[i],i });
	}
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
			int y;
			LL w;
			tie(y, w) = p;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				pq.push({ dis[y],y });
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
	return 0;
}