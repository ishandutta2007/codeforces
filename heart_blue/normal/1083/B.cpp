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
const int N = 5e5 + 10;
char s1[N];
char s2[N];
LL sum1[N];
LL sum2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s%s", s1 + 1, s2 + 1);
	int flag = 0;
	if (k == 1)
	{
		printf("%d\n", n);
		return 0;
	}
	k -= 2;
	LL ans = n;
	for (int i = 1; i <= n; i++)
	{
		if (flag)
		{
			if (s1[i] == 'a') sum1[n - i + 1]++;
			if (s2[i] == 'b') sum1[n - i + 1]++;
		}
		if (flag == 0)
		{
			if (s1[i] != s2[i])
			{
				flag = 1;
				ans += n - i + 1;
			}
		}
	}
	int cur = 0;
	for (int i = n; i >= 1; i--)
	{
		if (sum1[i] == 0 && sum2[i] == 0) continue;
		sum2[i] += sum1[i];
		for (int j = i - 1; j >= 1; j--)
		{
			int o = i - j - 1;
			if (o > 32) break;
			sum2[j] += ((sum1[i] * 1LL) << o);
			sum2[j] = min(sum2[j], INF);
		}
		sum2[i] = min(sum2[i], INF);
		int o = min(k, int(sum2[i]));
		k -= o;
		ans += 1LL * o * i;
	}
	printf("%lld\n", ans);
	return 0;
}