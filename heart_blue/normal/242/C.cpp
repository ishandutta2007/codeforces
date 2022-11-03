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
const int N = 5e5 + 10;
map<pair<int, int>, int> mp;
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	int n;
	cin >> n;
	while (n--)
	{
		int r, a, b;
		cin >> r >> a >> b;
		for (int i = a; i <= b; i++) mp[{r, i}] = INF;
	}
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	mp[{sx, sy}] = 0;
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		int d = mp[{x, y}];
		for (int i = 0; i < 8; i++)
		{
			int xx = dx[i] + x;
			int yy = dy[i] + y;
			if (mp.count({ xx,yy }))
			{
				int &tmp = mp[{xx, yy}];
				if (d + 1 < tmp)
				{
					tmp = d + 1;
					q.push({ xx,yy });
				}
			}
		}
	}
	int ans = mp[{ex, ey}];
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}