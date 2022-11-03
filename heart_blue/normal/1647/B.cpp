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
const int N = 1e2 + 10;
char str[N][N];
int a[N][N];
int sum(int x1, int y1, int x2, int y2)
{
	return a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
}
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
		MEM(str, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
			for (int j = 1; j <= m; j++)
			{
				a[i][j] = str[i][j] - '0' + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		}
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (str[i][j] == '0') continue;
				int u = i, d = i;
				int l = j, r = j;
				while (str[u][j] == '1') u--;
				while (str[d][j] == '1') d++;
				while (str[i][l] == '1') l--;
				while (str[i][r] == '1') r++;
				u++, d--, l++, r--;
				if (sum(u, l, d, r) != (d - u + 1) * (r - l + 1))
					flag = 0;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}