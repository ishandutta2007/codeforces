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
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		queue<pair<int, int>> q;
		int ninf = -INF;
		int a[4] = { ninf,ninf,ninf,ninf };
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
			for (int j = 1; j <= m; j++)
			{
				if (str[i][j] == 'B')
				{
					for (int o = 0; o < 4; o++)
					{
						int x = i, y = j;
						if (o & 1) x = i;
						else x = -i;
						if (o & 2) y = j;
						else y = -j;
						a[o] = max(a[o], x + y);
					}
				}
			}
		}
		tuple<int, int, int> ans = { 1000000,-1,-1 };
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int maxv = 0;
				for (int o = 0; o < 4; o++)
				{
					int x = i, y = j;
					if (o & 1) x = -i;
					else x = i;
					if (o & 2) y = -j;
					else y = j;
					maxv = max(maxv, a[o] + x + y);
				}
				ans = min(ans, { maxv,i,j });
			}
		}
		auto [d,x,y] = ans;
		printf("%d %d\n", x, y);
	}
	return 0;
}