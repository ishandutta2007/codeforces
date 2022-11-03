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
#include <chrono>
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
	int n, k;
	scanf("%d%d", &n, &k);
	map<int, int> mc;
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		mc[x]++;
		tot += x;
	}
	LL sum = 0;
	int cnt = 0;
	LL ans = INF * INF;
	for (auto [x, o] : mc)
	{
		if (o >= k)
		{
			puts("0");
			return 0;
		}
		int lcnt = cnt;
		int rcnt = n - cnt - o;
		cnt += o;
		LL lsum = sum;
		LL rsum = tot - sum - 1LL * x * o;
		sum += 1LL * x * o;
		LL lans = (x - 1LL) * lcnt - lsum;
		LL rans = rsum - (x + 1LL) * rcnt;
		if (o + lcnt >= k) ans = min(ans, lans + k - o);
		if (o + rcnt >= k) ans = min(ans, rans + k - o);
		ans = min(ans, lans + rans + k - o);
	}
	printf("%lld\n", ans);
	return 0;
}