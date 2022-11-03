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
const int N = 1e2 + 10;
int a[N][N];
int sum1[N];
int sum2[N];
int flag1[N];
int flag2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			sum1[i] += a[i][j];
			sum2[j] += a[i][j];
		}
	}
	while (1)
	{
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (sum1[i] < 0)
			{
				sum1[i] *= -1;
				flag1[i] ^= 1;
				flag = 1;
				for (int j = 1; j <= m; j++)
				{
					sum2[j] -= a[i][j] * 2;
					a[i][j] *= -1;
				}
			}
		}
		for (int j = 1; j <= m; j++)
		{
			if (sum2[j] < 0)
			{
				sum2[j] *= -1;
				flag2[j] ^= 1;
				flag = 1;
				for (int i = 1; i <= n; i++)
				{
					sum1[i] -= a[i][j] * 2;
					a[i][j] *= -1;
				}
			}
		}
		if (flag == 0) break;
	}
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++)
		if (flag1[i])
			v1.push_back(i);
	for (int i = 1; i <= m; i++)
		if (flag2[i])
			v2.push_back(i);
	printf("%d", v1.size());
	for (auto& x : v1)
		printf(" %d", x);
	puts("");
	printf("%d", v2.size());
	for (auto& x : v2)
		printf(" %d", x);
	puts("");
	return 0;
}