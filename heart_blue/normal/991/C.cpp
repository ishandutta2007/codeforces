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
	LL n;
	cin >> n;
	LL l = 1, r = INF * INF;
	LL ret = n;
	while (l <= r)
	{
		LL mid = (l + r) >> 1;
		LL x = n;
		LL ans1 = 0, ans2 = 0;
		while (x)
		{
			ans1 += min(mid, x);
			x -= min(mid, x);
			ans2 += x / 10;
			x -= x / 10;
		}
		if (ans1 >= ans2) ret = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ret << endl;
	return 0;
}