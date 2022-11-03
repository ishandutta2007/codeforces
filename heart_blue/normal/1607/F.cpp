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
const int N = 2e3 + 10;
char str[N][N];
int n, m;
int vis[N][N];
int in[N][N];
int dp[N][N];
pair<int, int> getnext(int x, int y)
{
	if (str[x][y] == 'L') y--;
	else if (str[x][y] == 'R') y++;
	else if (str[x][y] == 'U') x--;
	else if (str[x][y] == 'D') x++;
	return { x,y };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
		}
		for (int i = 0; i < n; i++)
		{
			fill(vis[i], vis[i] + m, 0);
		}
		tuple<int, int, int> ans = { -1,-1,-1 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int x = i, y = j;
				vector<pair<int, int>> vp;
				vp.emplace_back(i, j);
				while (1)
				{
					int x, y;
					tie(x, y) = vp.back();
					int cur = 0;
					int tx, ty;
					tie(tx, ty) = getnext(x, y);
					if (tx < 0 || ty < 0 || tx >= n || ty >= m)
					{
						cur = 1;
					}
					else if (vis[x][y])
					{
						vp.pop_back();
						cur = dp[x][y] + 1;
					}
					else if (in[x][y])
					{
						vp.pop_back();
						int pos = find(vp.begin(), vp.end(), make_pair(x, y)) - vp.begin();
						cur = vp.size() - pos;
						for (int o = 1; o <= cur; o++)
						{
							int tx, ty;
							tie(tx, ty) = vp.back();
							vp.pop_back();
							dp[tx][ty] = cur;
							in[tx][ty] = 0;
							vis[tx][ty] = 1;
						}
						cur++;
					}
					else
					{
						in[x][y] = 1;
						vp.emplace_back(tx, ty);
						continue;
					}
					while (!vp.empty())
					{
						int x, y;
						tie(x, y) = vp.back();
						vp.pop_back();
						dp[x][y] = cur++;
						vis[x][y] = 1;
						in[x][y] = 0;
					}
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ans = max(ans, { dp[i][j],i + 1,j + 1 });
			}
		}
		int x, y, d;
		tie(d, x, y) = ans;
		printf("%d %d %d\n", x, y, d);
	}
	return 0;
}