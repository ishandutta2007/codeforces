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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL k, d, t;
	cin >> k >> d >> t;
	t *= 2;
	d = (k - 1 + d) / d * d;
	LL o = k * 2 + d - k;
	LL tot = t / o * d;
	t %= o;
	if (k * 2 >= t)
	{
		tot += t / 2;
		printf("%lld.%d", tot, t % 2 == 0 ? 0 : 5);
		return 0;
	}
	t -= k * 2;
	tot += k + t;
	printf("%lld", tot);
	return 0;
}