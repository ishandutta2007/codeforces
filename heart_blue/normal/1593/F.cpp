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
#include <chrono>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e1 + 2;
int pre[N][N][N][N * 2][2][2];
char str[N];
char ans[N];
int build(int o, int x, int y, int t, int o1, int o2)
{
	int ret = 0;
	ret |= o2 << 0;
	ret |= o1 << 1;
	ret |= t << 2;
	ret |= y << 9;
	ret |= x << 15;
	ret |= o << 21;
	return ret;
}
tuple<int, int, int, int, int, int> check(int key)
{
	int o, x, y, t, o1, o2;
	o2 = key >> 0 & 1;
	o1 = key >> 1 & 1;
	t = key >> 2 & 127;
	y = key >> 9 & 63;
	x = key >> 15 & 63;
	o = key >> 21 & 1;
	return make_tuple(o, x, y, t, o1, o2);
}
void solve(int n, int a, int b)
{
	const int offset = 40;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			for (int k = 0; k < b; k++)
			{
				for (int t = 0; t <= offset * 2; t++)
				{
					for (int o1 = 0; o1 < 2; o1++)
					{
						for (int o2 = 0; o2 < 2; o2++)
						{
							if (pre[i][j][k][t][o1][o2] == -1) continue;

							{
								int& tmp = pre[i + 1]
									[(j * 10 + str[i + 1] - '0') % a][k][t + 1]
									[1][o2];
								tmp = build(0, j, k, t, o1, o2);
							}
							{
								int& tmp = pre[i + 1]
									[j][(k * 10 + str[i + 1] - '0') % b][t - 1]
									[o1][1];
								tmp = build(1, j, k, t, o1, o2);
							}
						}
					}
				}
			}
		}
	}
	for (int tt = 0; tt <= offset; tt++)
	{
		if (pre[n][0][0][offset + tt][1][1] != -1)
		{
			tt = offset + tt;
		}
		else if (pre[n][0][0][offset - tt][1][1] != -1)
		{
			tt = offset - tt;
		}
		else continue;
		MEM(ans, 0);
		int i = n;
		int j = 0;
		int k = 0;
		int t = tt;
		int o1 = 1;
		int o2 = 1;
		while (i > 0)
		{
			int res;
			
			//assert(i < N);
			//assert(j < N);
			//assert(k < N);
			//assert(t < N * 2);

			tie(res, j, k, t, o1, o2) = check(pre[i][j][k][t][o1][o2]);
			ans[i] = "RB"[res];
			i--;
		}
		puts(ans + 1);
		return;
	}
	puts("-1");
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	const int offset = 40;
	while (ncase--)
	{
		MEM(pre, -1);
		pre[0][0][0][offset][0][0] = 0;
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		scanf("%s", str + 1);
		solve(n, a, b);

	}
	return 0;
}