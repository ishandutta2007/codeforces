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
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &sum[i]);
		sum[i] += sum[i - 1];
	}
	LL cur = 0;
	while (q--)
	{
		LL x;
		scanf("%lld", &x);
		int o = upper_bound(sum + 1, sum + n + 1, cur + x) - sum;
		if (o > n)
		{
			cur = 0;
			printf("%d\n", n);
		}
		else
		{
			printf("%d\n", n - o + 1);
			cur += x;
		}
	}
	return 0;
}