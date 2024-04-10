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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e8 + 7;
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int c, m, x;
		cin >> c >> m >> x;
		int o = min({ c,m,x });
		c -= o;
		m -= o;
		x -= o;
		if (c > 0 && m > 0)
		{
			int minv = min(m, c);
			int l = 0, r = minv;
			int ret = 0;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (c - mid + m - mid >= mid) ret = mid, l = mid + 1;
				else r = mid - 1;
			}
			o += ret;
		}
		printf("%d\n", o);
	}
	return 0;
}