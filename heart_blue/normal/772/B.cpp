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
const int N = 2e3 + 10;
#define double long double
struct Point
{
	double x, y;
};
Point vp[N];
double dis(Point &p1, Point &p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx*dx + dy*dy);
}
double solve(int i, int j, int k)
{
	if (i == j || i == k || j == k) return 1e18;
	Point& p1 = vp[i];
	Point& p2 = vp[j];
	Point& p3 = vp[k];
	double a = dis(p1, p2);
	double b = dis(p2, p3);
	double c = dis(p1, p3);
	double p = (a + b + c) / 2;
	double s = sqrt(p*(p - a)*(p - b)*(p - c));
	double ans2 = min(s / a, min(s / b, s / c));
	double ans1 = min(a, min(b, c)) / 2;
	return min(ans1, ans2);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> vp[i].x >> vp[i].y;
	}
	double ans = 1e18;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double a = solve(i, j, (i + 1) % n);
			double b = solve(i, j, (i - 1 + n) % n);
			double c = solve(i, j, (j + 1) % n);
			double d = solve(i, j, (j - 1 + n) % n);
			ans = min(ans, min(min(a, b), min(c, d)));
		}
	}
	printf("%.15Lf\n", ans);
	return 0;
}