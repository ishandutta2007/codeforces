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
const int N = 50 + 10;
int flag1[N][N];
int flag2[N][N];
int n;
char str[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y, int flag[N][N], int key)
{
	if (x < 1 || x > n) return;
	if (y < 1 || y > n) return;
	if (str[x][y] == '1') return;
	if (flag[x][y]) return;
	flag[x][y] = key;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i], flag, key);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	int sx, sy;
	int ex, ey;
	cin >> sx >> sy;
	cin >> ex >> ey;
	for (int i = 1; i <= n; i++) cin >> (str[i] + 1);
	dfs(sx, sy, flag1, 1);
	dfs(ex, ey, flag2, 2);
	int ans = INF;

	for (int r1 = 1; r1 <= n; r1++)
	{
		for (int c1 = 1; c1 <= n; c1++)
		{
			if (flag1[r1][c1] != 1) continue;
			for (int r2 = 1; r2 <= n; r2++)
			{
				for (int c2 = 1; c2 <= n; c2++)
				{
					if (flag2[r2][c2] != 2) continue;
					int dx = r1 - r2;
					int dy = c1 - c2;
					ans = min(ans, dx*dx + dy * dy);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}