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
const int N = 4e2 + 10;
int a[N][N];
int dis[N];
int n, m;
int solve(int o)
{
	MEM(dis, -1);
	dis[1] = 0;
	list<int> l;
	l.push_back(1);
	while (!l.empty())
	{
		int x = l.front();
		l.pop_front();
		for (int i = 1; i <= n; i++)
		{
			if (a[x][i] == o && dis[i] == -1)
			{
				l.push_back(i);
				dis[i] = dis[x] + 1;
			}
		}
	}
	if (dis[n] == -1) dis[n] = INF;
	return dis[n];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	int ans = max(solve(0), solve(1));
	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}