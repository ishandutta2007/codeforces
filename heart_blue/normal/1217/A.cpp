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
		int a, b, c;
		cin >> a >> b >> c;
		if (a + c <= b)
		{
			puts("0");
			continue;
		}
		int l = 0, r = c;
		int res = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (a + mid > c - mid + b) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", c - res + 1);
	}
	return 0;
}