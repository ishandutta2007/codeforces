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
const int N = 4e5 + 10;
LL sum(LL x)
{
	return x * (x + 1) / 2;
}
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
		LL x;
		scanf("%lld", &x);
		LL l = 1, r = 2 * n - 1;
		LL ret = 2 * n - 1;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			LL tot = 0;
			if (mid <= n) tot += sum(mid);
			else tot += sum(n - 1) + sum(n) - sum(2 * n - 1 - mid);
			if (tot >= x) ret = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ret);
	}
	return 0;
}