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
const int N = 3e3 + 10;
int dis[N][N];
vector<int> v[N];
void init(int o)
{
	MEM(dis[o], 0x3f);
	dis[o][o] = 0;
	queue<int> q;
	q.push(o);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto &y : v[x])
		{
			if (dis[o][y] > dis[o][x] + 1)
			{
				dis[o][y] = dis[o][x] + 1;
				q.push(y);
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
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) init(i);
	int u1, v1, w1;
	int u2, v2, w2;
	cin >> u1 >> v1 >> w1;
	cin >> u2 >> v2 >> w2;
	if (dis[u1][v1] > w1 || dis[u2][v2] > w2)
	{
		cout << -1 << endl;
		return 0;
	}
	int ans = max(0, m - dis[u1][v1] - dis[u2][v2]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int len1 = min(dis[i][u1] + dis[j][v1], dis[i][v1] + dis[j][u1]) + dis[i][j];
			int len2 = min(dis[i][u2] + dis[j][v2], dis[i][v2] + dis[j][u2]) + dis[i][j];
			if (len1 <= w1 && len2 <= w2)
			{
				ans = max(ans, m - len1 - len2 + dis[i][j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}