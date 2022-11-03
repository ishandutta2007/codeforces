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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
LL d, k, a, b, t;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> d >> k >> a >> b >> t;
	LL l = 0;
	LL r = d / k;
	auto check = [&](LL x) -> LL
	{
		LL ret = k*x*a;
		LL res = d - k*x;
		LL r = min(k, res);
		ret += r*a + (res - r)*b + x*t;
		return ret;
	};
	LL key = r;
	while (l <= r)
	{
		LL mid = (l + r) >> 1;
		LL midmid = (mid + r + 1) >> 1;
		LL lval = check(mid);
		LL rval = check(midmid);
		if (lval > rval) l = mid + 1, key = midmid;
		else r = midmid - 1, key = mid;
	}
	cout << check(key) << endl;
	return 0;
}