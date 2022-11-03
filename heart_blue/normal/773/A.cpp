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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL x, y, p, q;
		cin >> x >> y >> p >> q;
		LL ans = -1;
		LL l = 1, r = INF;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			if (p * mid >= x && q * mid >= y && q*mid - y >= p*mid - x) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		if (ans != -1) ans = q*ans - y;
		cout << ans << endl;
	}
	return 0;
}