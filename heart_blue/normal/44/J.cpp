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
const int N = 1e3 + 10;
vector<pair<int, int>> vp[N * N];
char str[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	MEM(str, ' ');
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] != 'b') continue;
			if (str[i][j - 1] != 'w' || str[i][j + 1] != 'w')
			{
				puts("NO");
				return 0;
			}
			vp[tot].emplace_back(i, j - 1);
			vp[tot].emplace_back(i, j);
			vp[tot].emplace_back(i, j + 1);
			tot++;
			str[i][j] = str[i][j - 1] = str[i][j + 1] = '.';
		}
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] != 'w') continue;
			if (str[i + 1][j] != 'b' || str[i + 2][j] != 'w')
			{
				puts("NO");
				return 0;
			}
			vp[tot].emplace_back(i, j);
			vp[tot].emplace_back(i + 1, j);
			vp[tot].emplace_back(i + 2, j);
			tot++;
			str[i][j] = str[i + 1][j] = str[i + 2][j] = '.';
		}
	}
	for (int o = 0; o < tot; o++)
	{
		set<char> s;
		for (int i = 'a'; i <= 'd'; i++)
			s.emplace(i);
		for (auto [x, y] : vp[o])
		{
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];
				s.erase(str[tx][ty]);
			}
		}
		char c = *s.begin();
		for (auto [x, y] : vp[o])
		{
			str[x][y] = c;
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		puts(str[i] + 1);
	return 0;
}