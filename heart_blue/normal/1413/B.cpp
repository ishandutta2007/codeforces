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
const int N = 5e2 + 10;
int flag[N * N];
int a[N][N];
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
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int j = 1; j <= m; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				int x;
				scanf("%d", &x);
				flag[x] = i;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int k = 1;
			for (int j = 1; j <= n; j++)
			{
				if (flag[a[j][1]] == i)
				{
					k = j;
					break;
				}
			}
			for (int j = 1; j <= m; j++)
			{
				printf("%d ", a[k][j]);
			}
			puts("");
		}
	}
	return 0;
}