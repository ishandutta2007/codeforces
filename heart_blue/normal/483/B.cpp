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
const int N = 1e2 + 10;
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cnt1, cnt2;
	cin >> cnt1 >> cnt2; 
	LL x, y;
	cin >> x >> y;
	LL lcm = x/ gcd(x, y) * y;
	LL l = 1, r = INF*INF;
	LL ans = 1;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		LL a = mid - mid / x;
		LL b = mid - mid / y;
		LL g = mid - (mid/x + mid/y - mid/lcm);
		a -= g;
		b -= g;
		g -= max(0LL, cnt1 - a);
		g -= max(0LL, cnt2 - b);
		if (g >= 0) ans = mid, r = mid - 1;
		else l = mid + 1;

	}
	cout << ans << endl;
	return 0;
}