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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		ans += a[i] - 1;
	}
	sort(a + 1, a + n + 1);
	for (int o = 2; o <= 100000; o++)
	{
		LL sum = 0;
		LL cur = 1;
		for (int i = 1; i <= n; i++)
		{
			if (cur >= 10000 * INF)
			{
				sum = INF * INF;
				break;
			}
			sum += abs(cur - a[i]);
			cur *= o;
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}