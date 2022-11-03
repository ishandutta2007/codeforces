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
LL solve(LL n)
{
	if (n == 0) return 0;
	LL r = sqrtl(n) + 10;
	while (r * r > n) r--;
	LL ans = (r - 1) * 3;
	for (LL i = r * r; i <= n; i += r)
	{
		ans++;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(r) - solve(l - 1));
	}
	return 0;
}