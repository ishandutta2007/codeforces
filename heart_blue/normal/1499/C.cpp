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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int minv1 = INF, minv2 = INF;
		LL sum1 = 0, sum2 = 0;
		int cnt1 = 0, cnt2 = 0;
		LL ans = INF * INF;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (i & 1) minv1 = min(minv1, x), cnt1++, sum1 += x;
			else minv2 = min(minv2, x), cnt2++, sum2 += x;
			if (i == 1) continue;
			ans = min(ans, sum1 + sum2 + (n - cnt1) * 1LL * minv1 + (n - cnt2) * 1LL * minv2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}