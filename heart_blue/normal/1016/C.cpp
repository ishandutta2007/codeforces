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
LL a[N];
LL b[N];
LL suma[N];
LL sumb[N];
LL sumsuma[N];
LL sumsumb[N];
void init(LL *a, LL *suma, LL *sumsuma, int n)
{
	for (int i = 1; i <= n; i++)
	{
		suma[i] = a[i] + suma[i - 1];
		sumsuma[i] = sumsuma[i - 1] + 1LL*i * a[i];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	init(a, suma, sumsuma, n);
	init(b, sumb, sumsumb, n);
	LL ans = 0;
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		LL sum = 0;
		if (i & 1)
		{
			sum += (sumsuma[n] - sumsuma[i - 1]) + (2 * i - 2 - i)*(suma[n] - suma[i - 1]);
			sum += (sumb[n] - sumb[i - 1])*(2 * n - 1 + i) - (sumsumb[n] - sumsumb[i - 1]);
		}
		else
		{
			sum += (sumsumb[n] - sumsumb[i - 1]) + (2 * i - 2 - i)*(sumb[n] - sumb[i - 1]);
			sum += (suma[n] - suma[i - 1])*(2 * n - 1 + i) - (sumsuma[n] - sumsuma[i - 1]);
		}
		ans = max(ans, tot + sum);
		if (i & 1) tot += (2 * i - 2)*a[i] + (2 * i - 1)*b[i];
		else tot += (2 * i - 1)*a[i] + (2 * i - 2)*b[i];
	}
	ans = max(ans, tot);
	printf("%lld\n", ans);
	return 0;
}