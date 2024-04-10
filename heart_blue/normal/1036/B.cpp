#pragma comment(linker, "/STACK:102400000,102400000") 
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
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		LL x, y, k;
		cin >> x >> y >> k;
		if (k < max(x, y))
		{
			puts("-1");
			continue;
		}
		if (x < y) swap(x, y);
		LL ans = y;
		x -= y;
		k -= y;
		ans += x / 2 * 2;
		k -= x / 2 * 2;
		x &= 1;
		if (x)
			ans += k - 1;
		else
		{
			if (k & 1) ans += k - 2;
			else ans += k;
		}
	
		printf("%lld\n", ans);
	}
	return 0;
}