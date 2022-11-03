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
int dis1[N], dis2[N];
vector<int> v[N];
void solve(int s, int dis[])
{
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto &y : v[x])
		{
			if (dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	MEM(dis1, 0x3f);
	MEM(dis2, 0x3f);
	map<pair<int, int>, int> mc;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		if (x > y) swap(x, y);
		mc[{x, y}] = 1;
	}
	solve(s, dis1);
	solve(t, dis2);
	int d = dis1[t];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (mc.count({ i,j })) continue;
			int minv = min(dis1[i] + dis2[j] + 1, dis1[j] + dis2[i] + 1);
			if (minv >= d) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}