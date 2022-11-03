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
const int N = 5e2 + 10;
int dp2[N][N];
int dp1[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	MEM(dp2, -1);
	MEM(dp1, 0x3f);
	dp1[0] = 0;
	for (int i = n; i >= 1; i--)
	{
		dp2[i][i] = a[i];
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = i; k < j; k++)
			{
				if (dp2[i][k] == dp2[k + 1][j] && dp2[i][k] != -1)
				{
					dp2[i][j] = dp2[i][k] + 1;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (dp2[j][i] != -1)
				dp1[i] = min(dp1[i], dp1[j - 1] + 1);
		}
	}
	printf("%d\n", dp1[n]);
	return 0;
}