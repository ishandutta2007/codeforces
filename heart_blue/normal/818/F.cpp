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
const int N = 1e6 + 10;
LL cal(LL n, LL k)
{
	return n - k + min(k * (k - 1) / 2, n - k);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n;
		scanf("%lld", &n);
		LL l = 1, r = n;
		LL ans = n - 1;
		while (r - l >= 10)
		{
			LL mid1 = (l + r) / 2;
			LL mid2 = (mid1 + r) / 2;
			LL res1 = cal(n, mid1);
			LL res2 = cal(n, mid2);
			ans = max({ ans,res1,res2 });
			if (res1 < res2) l = mid1 + 1;
			else r = mid2 - 1;
		}
		for (int i = l; i <= r; i++)
			ans = max(ans, cal(n, i));
		printf("%lld\n", ans);
	}
	return 0;
}