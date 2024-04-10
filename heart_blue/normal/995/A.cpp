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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int flag[10][N];
pair<int, int> des[N];
pair<int, int> pos[N];
int vis[10][N];
int n = 4, m;
int k;
vector<tuple<int, int, int>> ans;
void moveto(int& x, int& y, int tx, int ty)
{
	int id = flag[x][y];
	if (id == 0) return;
	flag[x][y] = 0;
	flag[tx][ty] = id;
	pos[id] = { tx,ty };
	while (x != tx)
	{
		if (x > tx) x--;
		else x++;
		ans.emplace_back(id, x, y);
	}
	while (y != ty)
	{
		if (y > ty) y--;
		else y++;
		ans.emplace_back(id, x, y);
	}
}
int a[10][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			a[i][j] = x;
			if (x == 0) continue;
			if (i == 1 || i == 4)
			{
				des[x] = { i,j };
			}
			else
			{

				flag[i][j] = x;
				pos[x] = { i,j };
			}
		}
	}
	vector<pair<int, int>> key;
	for (int i = 1; i <= m; i++)
		key.emplace_back(2, i);
	for (int i = m; i >= 1; i--)
		key.emplace_back(3, i);

	while (1)
	{
		int cnt = 0;
		int ok = 0;
		for (int i = 1; i <= k; i++)
		{
			if (pos[i] == des[i])
			{
				cnt++;
				continue;
			}
			auto [sx, sy] = pos[i];
			auto [tx, ty] = des[i];
			if (abs(sx - tx) + abs(sy - ty) == 1)
			{
				moveto(sx, sy, tx, ty);
			}
		}
		if (cnt == k) break;
		int r = 0;
		while (1)
		{
			auto [x, y] = key.front();
			if (flag[x][y] == 0)
			{
				for (int i = 1; i < key.size(); i++)
				{
					auto [sx, sy] = key[i];
					auto [tx, ty] = key[i - 1];
					moveto(sx, sy, tx, ty);
				}
				break;
			}
			r++;
			if (r > 1000)
			{
				puts("-1");
				return 0;
			}
			key.push_back(key.front());
			key.erase(key.begin());
		}
	}

	printf("%d\n", ans.size());
	for (auto [id, x, y] : ans)
		printf("%d %d %d\n", id, x, y);
	return 0;
}