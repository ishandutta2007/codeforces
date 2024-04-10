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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e3 + 10;
vector<int> v[N];
vector<pair<int,int>> v1[N], v2[N];
int dis[N][N];
void refrain(vector<pair<int, int>> &vp, pair<int,int> p)
{
	if (vp.size() < 3) vp.push_back(p);
	else
	{
		if (vp.back() < p)
			vp.back() = p;
	}
	sort(vp.rbegin(), vp.rend());
}
void solve(int s)
{
	MEM(dis[s], 0x3f);
	int *d = dis[s];
	queue<int> q;
	q.push(s);
	d[s] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto &y : v[x])
		{
			if (d[y] > d[x] + 1)
			{
				d[y] = d[x] + 1;
				refrain(v1[y], { d[y],s });
				refrain(v2[s], { d[y],y });
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
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		solve(i);
	tuple<int, int, int, int, int> ans = { 0,0,0,0,0 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] == 0x3f3f3f3f) continue;
			if (i == j) continue;
			for (auto &p1 : v1[i])
			{
				if (p1.second == j) continue;
				for (auto &p2 : v2[j])
				{
					if (p2.second == i || p2.second == p1.second) continue;
					ans = max(ans, { dis[i][j] + p1.first + p2.first, p1.second, i, j, p2.second });
				}
			}
		}
	}
	int a, b, c, d;
	tie(ignore, a, b, c, d) = ans;
	printf("%d %d %d %d\n", a, b, c, d);
	return 0;
}