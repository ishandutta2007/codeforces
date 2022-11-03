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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e2 + 10;
vector<int> v[N];
int a[N][N];
vector<pair<int, int>> vp[N];
int flag[N];
const int mod = 998244353;
int res[N][N];
void floyd(int n)
{
	for (int i = 1; i <= n; i++)
		a[i][i] = 0;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	MEM(a, 0x3f);
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	floyd(n);
	for (int x = 1; x <= n; x++)
	{
		for (int y = x; y <= n; y++)
		{
			int d = a[x][y];
			LL ans = 1;
			vector<int> vv;
			for (int i = 0; i <= d; i++) vp[i].clear();
			for (int i = 1; i <= n; i++)
			{
				if (a[x][i] + a[y][i] < d)
				{
					ans = 0;
					break;
				}
				if (a[x][i] + a[y][i] == d)
				{
					vv.push_back(i);
				}
				int len = (a[x][i] - a[y][i] + d);
				if (len & 1)
				{
					ans = 0;
					continue;
				}
				len /= 2;
				vp[len].emplace_back(a[x][i], i);
			}
			if (ans == 0 || vv.size() != d + 1)
			{
				continue;
			}
			MEM(flag, -1);
			for (int i = 0; i <= d; i++)
			{
				sort(vp[i].begin(), vp[i].end());
				if (vp[i].empty())
				{
					ans = 0;
					break;
				}
				int o = vp[i][0].second;
				if (a[x][o] + a[y][o] != d)
				{
					ans = 0;
					break;
				}
				flag[vp[i][0].second] = i;
				for (int j = 1; j < vp[i].size(); j++)
				{
					int o1 = vp[i][j].second;
					flag[o1] = i;
					int cnt = 0;
					for (auto& o2 : v[o1])
					{
						if (flag[o2] == i && a[x][o2] + 1 == a[x][o1])
						{
							cnt++;
						}
					}
					ans = ans * cnt % mod;
				}
				if (ans == 0) break;
			}
			res[x][y] = res[y][x] =ans;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", res[i][j]);
		}
		puts("");
	}
	return 0;
}