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
const int N = 2e5 + 10;
int v[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		int p = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &v[i]);
			sum[i] = v[i] + sum[i - 1];
		}
		LL ans = INF * INF;
		LL cur = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = min(ans,
				cur + ((sum[n] - sum[i - 1]) - (n - i + 1LL) * v[i - 1]) * b);
			cur += 1LL * (a + b) * (v[i] - v[i - 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}