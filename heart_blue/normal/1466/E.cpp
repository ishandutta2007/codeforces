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
const int N = 5e5 + 10;
int cnt[66];
LL a[N];
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
		MEM(cnt, 0);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			for (int o = 0; o < 60; o++)
			{
				cnt[o] += a[i] >> o & 1;
			}
		}
		LL ans = 0;
		for (int i = 0; i < n; i++)
		{
			LL lans = 0;
			LL rans = 0;
			for (int o = 0; o < 60; o++)
			{
				if (a[i] >> o & 1)
				{
					lans += (1LL << o) % INF * cnt[o] % INF;
					rans += (1LL << o) % INF * n % INF;
				}
				else
				{
					rans += (1LL << o) % INF * cnt[o] % INF;
				}
			}
			lans %= INF;
			rans %= INF;
			ans += lans * rans % INF;
		}
		printf("%lld\n", ans % INF);
	}
	return 0;
}