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
const int N = 1e2 + 10;
int flag[N][N];
int a[N][N];
int b[N][N];
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
		MEM(flag, 0);
		int ans = 0;
		for (int k = 1; k <= m; k++)
		{
			int kx = 1, ky = 1;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (a[i][j] < a[kx][ky])
						kx = i, ky = j;
				}
			}
			ans += a[kx][ky];
			flag[kx][ky] = 1;
			for (int i = 1; i <= n; i++)
			{
				if (kx == i)
				{
					b[i][k] = a[kx][ky];
					continue;
				}
				int maxv = 0;
				int key = 0;
				for (int j = 1; j <= m; j++)
				{
					if (flag[i][j]) continue;
					if (a[i][j] > maxv)
						maxv = a[i][j], key = j;
				}
				b[i][k] = maxv;
				flag[i][key] = 1;
				a[i][key] = INF;
			}
			a[kx][ky] = INF;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				printf("%d ", b[i][j]);
			}
			puts("");
		}
	}
	return 0;
}