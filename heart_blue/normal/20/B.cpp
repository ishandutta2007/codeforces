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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b, c;
	cin >> a >> b >> c;
	if (a == 0)
	{
		if (b != 0)
		{
			puts("1");
			printf("%.15f\n", c * 1.0 / -b);
		}
		else
		{
			if (c == 0) puts("-1");
			else puts("0");
		}
	}
	else
	{
		LL delta = b*b - 4 * a*c;
		if (delta < 0) puts("0");
		if (delta == 0)
		{
			puts("1");
			printf("%.15f\n", -b / 2.0 / a);
		}
		if (delta > 0)
		{
			double d = sqrt(delta);
			puts("2");
			double x1 = (-b - d) / 2 / a;
			double x2 = (-b + d) / 2 / a;
			if (x1 > x2) swap(x1, x2);
			printf("%.15f\n%.15f\n", x1, x2);
		}
	}
	return 0;
}