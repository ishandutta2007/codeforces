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
const int N = 3e5 + 10;
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
		LL k;
		scanf("%d%lld", &n, &k);
		LL tot = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			tot += a[i];
		}
		if (tot <= k)
		{
			puts("0");
			continue;
		}
		LL ans = tot - k;
		LL sum = 0;
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		for (int i = 1; i < n; i++)
		{
			sum += a[i] - a[n];
			if (tot - sum <= k)
			{
				ans = min(ans, i * 1LL);
				continue;
			}
			LL cost = i + (tot - sum - k + i) / (i + 1);
			ans = min(ans, cost);
		}
		printf("%lld\n", ans);
		
	}
	return 0;
}