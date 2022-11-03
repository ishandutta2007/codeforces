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
LL suml0[N], suml1[N];
LL sumr0[N], sumr1[N];
char str[N];
LL cnt0[N], cnt1[N], cnt2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	int x, y;
	scanf("%d%d", &x, &y);
	for (int i = 1; i <= n; i++)
	{
		suml0[i] = suml0[i - 1];
		suml1[i] = suml1[i - 1];
		cnt0[i] = cnt0[i - 1] + (str[i] == '0');
		cnt1[i] = cnt1[i - 1] + (str[i] == '1');
		cnt2[i] = cnt2[i - 1] + (str[i] == '?');
		if (str[i] == '0' || str[i] == '?')
		{
			suml0[i] += y * cnt1[i - 1];
		}
		else
		{
			suml0[i] += x * (cnt0[i - 1] + cnt2[i - 1]);
		}
		if (str[i] == '1' || str[i] == '?')
		{
			suml1[i] += x * cnt0[i - 1];
		}
		else
		{
			suml1[i] += y * (cnt1[i - 1] + cnt2[i - 1]);
		}
	}
	LL ans = min(suml1[n], suml0[n]);
	for (int i = n; i >= 1; i--)
	{
		LL sum0 = suml0[i] + sumr1[i + 1] +
			(cnt0[i] + cnt2[i]) * (cnt1[n] - cnt1[i] + cnt2[n] - cnt2[i]) * x +
			cnt1[i] * (cnt0[n] - cnt0[i]) * y;
		LL sum1 = suml1[i] + sumr0[i + 1] +
			(cnt1[i] + cnt2[i]) * (cnt0[n] - cnt0[i] + cnt2[n] - cnt2[i]) * y +
			cnt0[i] * (cnt1[n] - cnt1[i]) * x;
		ans = min({ ans,sum0,sum1 });
		sumr0[i] = sumr0[i + 1];
		sumr1[i] = sumr1[i + 1];
		if (str[i] == '0' || str[i] == '?')
		{
			sumr0[i] += x * (cnt1[n] - cnt1[i]);
		}
		else
		{
			sumr0[i] += y * (cnt0[n] - cnt0[i] + cnt2[n] - cnt2[i]);
		}
		if (str[i] == '1' || str[i] == '?')
		{
			sumr1[i] += y * (cnt0[n] - cnt0[i]);
		}
		else
		{
			sumr1[i] += x * (cnt1[n] - cnt1[i] + cnt2[n] - cnt2[i]);
		}

	}
	printf("%lld\n", ans);
	return 0;
}