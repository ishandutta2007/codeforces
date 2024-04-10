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
int a[N];
double dis(double x1, double y1, double x2, double y2)
{
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx*dx + dy * dy);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int r, a, b, x, y;
	cin >> r >> a >> b >> x >> y;
	if (a == x && y == b)
	{
		printf("%.15f %.15f %.15f\n", a*1.0, b + r/ 2.0, r/2.0);
		return 0;
	}
	double d = dis(x, y, a, b);
	if (d > r)
	{
		printf("%d %d %d", a, b, r);
		return 0;
	}
	x -= a, y -= b;
	double rx = -1.0*x * r / d, ry = -1.0*y * r / d;
	printf("%.15f %.15f %.15f\n", (x + rx) / 2 + a, (y + ry) / 2 + b, dis(x, y, rx, ry) / 2);

	return 0;
}