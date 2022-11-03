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
vector<pair<double, double>> vp;
void add1(int a, int b, int c, double x)
{
	if (b == 0) return;
	vp.emplace_back(x, (-c - a * x) / b);
}
void add2(int a, int b, int c, double y)
{
	if (a == 0) return;
	vp.emplace_back((-c - b * y) / a, y);
}
double dis1(double x1, double y1, double x2, double y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}
double dis2(double x1, double y1, double x2, double y2)
{
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double ans = dis1(x1, y1, x2, y2);
	add1(a, b, c, x1);
	add1(a, b, c, x2);
	add2(a, b, c, y1);
	add2(a, b, c, y2);
	for (auto& p1 : vp)
	{
		for (auto& p2 : vp)
		{
			ans = min(ans, dis2(p1.first, p1.second, p2.first, p2.second)
				+ dis1(p1.first, p1.second, x1, y1)
				+ dis1(p2.first, p2.second, x2, y2));
		}
	}
	printf("%.15f\n", ans);
	return 0;
}