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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL a[2][N];
LL maxv1[2][N];
LL maxv2[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int o = 0; o < 2; o++)
		{
			for (int i = 1; i <= n; i++)
			{
				scanf("%lld", &a[o][i]);
				maxv1[o][i] = a[o][i] - i;
				maxv2[o][i] = a[o][i] - (n - i);
			}
			for (int i = n - 1; i >= 1; i--)
			{
				maxv1[o][i] = max(maxv1[o][i], maxv1[o][i + 1]);
				maxv2[o][i] = max(maxv2[o][i], maxv2[o][i + 1]);
			}
		}
		LL ans = INF * INF;
		LL key0 = 0, key1 = INF * INF;
		for (int i = 1; i <= n; i++)
		{
			if (i == n)
			{
				ans = min({ ans,max(key0,a[1][i]) + 1,max(key1,a[0][i]) + 1 });
				break;
			}
			LL key[2] = { key0,key1 };
			for (int o = 0; o < 2; o++)
			{
				LL x = max({ key[o],maxv1[o][i + 1] + (i + 1), maxv2[o ^ 1][i] - (n - i) });
				ans = min(ans, x + (n - i) * 2 + 1);
			}
			tie(key0, key1) = make_pair(max(key1, a[0][i]) + 1, max(key0, a[1][i]) + 1);
			key0 = max(key0, a[0][i + 1]) + 1;
			key1 = max(key1, a[1][i + 1]) + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}