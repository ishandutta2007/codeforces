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
const LL INF = 1e9 + 9;
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
/*
d = n/x;
(d-1)/k+1 <= D;
*/
	LL n, k, m, d;
	cin >> n >> k >> m >> d;
	LL ans = 0;
	for (int i = 1; i <= d; i++)
	{
		LL l = 1, r = m;
		LL ret = 1;
		while (l <= r)
		{
			LL mid = (l + r) >> 1;
			if ((n / mid - 1) / k + 1 >= i) ret = mid, l = mid + 1;
			else r = mid - 1;
		}
		if ((n / ret - 1) / k + 1 == i) ans = max(ans, ret*i);
	}
	cout << ans << endl;
	return 0;
}