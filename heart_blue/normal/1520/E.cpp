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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
LL sum1[N];
LL sum2[N];
char str[N];
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
		scanf("%s", str + 1);
		int cur = 0;
		for (int i = 1; i <= n; i++)
		{
			sum1[i] = sum1[i - 1];
			if (str[i] != '.') cur++;
			else sum1[i] += cur;
		}
		sum2[n + 1] = 0;
		cur = 0;
		for (int i = n; i >= 1; i--)
		{
			sum2[i] = sum2[i + 1];
			if (str[i] != '.') cur++;
			else sum2[i] += cur;
		}
		LL ans = INF * INF;
		for (int i = 0; i <= n; i++)
		{
			ans = min(ans, sum1[i] + sum2[i + 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}