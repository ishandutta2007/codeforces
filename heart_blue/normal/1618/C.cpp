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
const int N = 2e5 + 10;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n % m);
}
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		LL ans = 0;
		for (int o = 0; o < 2; o++)
		{
			LL g = 0;
			for (int i = 1; i <= n; i++)
			{
				if ((i & 1) == o)
					g = gcd(g, a[i]);
			}
			int flag = 1;
			for (int i = 1; i <= n; i++)
			{
				if ((i & 1) != o && a[i] % g == 0)
				{
					flag = 0;
				}
			}
			if (flag)
				ans = g;
		}
		printf("%lld\n", ans);
	}
	return 0;
}