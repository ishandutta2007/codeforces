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
const int N = 2e5 + 20;
int a[N];
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
			scanf("%d", &a[i]);
		if (is_sorted(a + 1, a + n + 1))
		{
			puts("0");
			continue;
		}
		if (a[n - 1] > a[n])
		{
			puts("-1");
			continue;
		}
		if (a[n] >= 0)
		{
			printf("%d\n", n - 2);
			for (int i = 1; i <= n - 2; i++)
			{
				printf("%d %d %d\n", i, n - 1, n);
			}
			continue;
		}
		puts("-1");
	}
	return 0;
}