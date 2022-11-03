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
const int N = 3e2 + 10;
int dx[] = { -1,1,0,0,0 };
int dy[] = { 0,0,-1,1,0 };
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	vector<tuple<int, int, int>> ans;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] != '*') continue;
			for (int k = 1; k <= n; k++)
			{
				int cnt = 0;
				for (int o = 0; o < 4; o++)
				{
					int x = i + dx[o] * k;
					int y = j + dy[o] * k;
					if (x < 1 || x > n) break;
					if (y < 1 || y > m) break;
					cnt += str[x][y] == '*';
				}
				if (cnt == 4)
					ans.emplace_back(k, i, j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	if (k > ans.size()) puts("-1");
	else
	{
		int r, x, y;
		tie(r, x, y) = ans[k - 1];
		printf("%d %d\n", x, y);
		for (int o = 0; o < 4; o++)
		{
			printf("%d %d\n", x + dx[o] * r, y + dy[o] * r);
		}
	}
	return 0;
}