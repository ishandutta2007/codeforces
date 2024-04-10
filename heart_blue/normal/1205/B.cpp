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
const int N = 3e5 + 10;
int cnt[100][100];
int a[200][200];
int dis[200][200];
LL v[N];
int ans = INF;
void solve(int n)
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ans = min(ans, dis[i][j] + a[i][k] + a[k][j]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		LL x;
		scanf("%lld", &x);
		if (x == 0)
		{
			i--;
			n--;
			continue;
		}
		v[i] = x;
		for (int o1 = 0; x >> o1; o1++)
		{
			if (x >> o1 & 1)
			{
				for (int o2 = o1; x >> o2; o2++)
				{
					if (x >> o2 & 1)
					{
						cnt[o1][o2]++;
						if (cnt[o1][o2] > 2)
						{
							puts("3");
							return 0;
						}
					}
				}
			}
		}
	}
	MEM(a, 0x01);
	MEM(dis, 0x01);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (v[i] & v[j])
				a[i][j] = a[j][i] = dis[j][i] = dis[i][j] = 1;
		}
	}
	solve(n);
	if (ans > n) ans = -1;
	printf("%d\n", ans);
	return 0;
}