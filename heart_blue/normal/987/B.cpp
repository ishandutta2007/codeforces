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
const int N = 2e5 + 10;
int mypow(int a, int b)
{
	int ret = 1;
	while (b--) ret *= a;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, y;
	cin >> x >> y;
	if (x == y)
	{
		puts("=");
		return 0;
	}
	if (x == 1)
	{
		puts("<");
		return 0;
	}
	if (y == 1)
	{
		puts(">");
		return 0;
	}
	if (x <= 4 && y <= 4)
	{
		int a = mypow(x, y);
		int b = mypow(y, x);
		if (a == b) puts("=");
		if (a < b) puts("<");
		if (a > b) puts(">");
		return 0;
	}
	if (x < y) puts(">");
	else puts("<");
	return 0;
}