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
const int N = 1e6 + 10;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, y;
	cin >> n >> x >> y;
	while (n--)
	{
		int a;
		cin >> a;
		a %= (x + y);
		LL l = 0, r = 1LL * x*y;
		LL res = l;
		LL lcm = x / gcd(x, y)*y;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			if (mid / x + mid / y >= a) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		if (res % lcm == 0) puts("Both");
		else if (res % y == 0) puts("Vanya");
		else puts("Vova");
	}
	
	return 0;
}