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
const int N = 1e3 + 10;
const double eps = 1e-4;
double pi = acos(0.0) * 2;
struct Point
{
	double x, y;
};
double dis(Point& p1, Point &p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx*dx + dy*dy);
}
double getangel(double a, double b, double c)
{
	return acos((a*a + b*b - c*c) / (2 * a*b));
}
double gcd(double n, double m)
{
	return abs(m) < eps ? n : gcd(m, n - int(n / m)*m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	Point A, B, C;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	double a = dis(B, C);
	double b = dis(A, C);
	double c = dis(A, B);
	double p = (a + b + c) / 2;
	double S = sqrt(p*(p - a)*(p - b)*(p - c));
	double r = a*b*c / 4 / S;
	double alpha = getangel(b, c, a);
	double beta = getangel(a, c, b);
	double theta = getangel(a, b, c);
	double g = gcd(alpha, gcd(beta, theta));
	double edge = pi / g;
	printf("%.15f\n", edge*0.5*r*r*sin(g * 2));
	return 0;
}