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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		LL n, k;
		scanf("%lld%lld", &n, &k);
		LL rest = n - 1;
		LL cur = 1;
		LL cost = 0;
		while (rest)
		{
			if (cur >= k) break;
			LL o = min({ cur, k,rest });
			cur += o;
			rest -= o;
			cost++;
		}
		cost += (rest + k - 1) / k;
		printf("%lld\n", cost);
	}
	return 0;
}