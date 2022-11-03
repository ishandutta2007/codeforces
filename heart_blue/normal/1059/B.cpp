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
const int N = 2e3 + 10;
char c[N][N];
char c1[N][N];
int dx[] = { 1,1,1,-1,-1,-1,0,0 };
int dy[] = { 1,0,-1,1,0,-1,1,-1 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", c[i] + 1);
	MEM(c1, '.');
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < m; j++)
		{
			int cnt = 0;
			for (int o = 0; o < 8; o++)
			{
				cnt += c[i + dx[o]][j + dy[o]] == '#';
			}
			if (cnt == 8)
			{
				for (int o = 0; o < 8; o++)
				{
					c1[i + dx[o]][j + dy[o]] = '#';
				}
			}
		}
	}
	int flag = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] != c1[i][j])
				flag = 0;
		}
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}