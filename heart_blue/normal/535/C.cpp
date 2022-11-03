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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b, n;
	cin >> a >> b >> n;
	while (n--)
	{
		LL l, t, m;
		cin >> l >> t >> m;
		int r = t;
		int ans = -1;
		LL x = a + (l - 1)*b;
		int o = l;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			LL y = a + (mid - 1)*b;
			if (y > t) r = mid - 1;
			else if ((x + y)*(mid - o + 1) / 2 > m * t) r = mid - 1;
			else ans = mid, l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}