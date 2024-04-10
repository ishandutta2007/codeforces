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
const int N = 5e3 + 10;
pair<double, double> check(double x, double y, double m)
{
	long double a1 = (x - m)*(y - m);
	long double a2 = (x - m)*(y + m);
	long double a3 = (x + m)*(y - m);
	long double a4 = (x + m)*(y + m);
	return { min(min(a1,a2),min(a3,a4)),
		max(max(a1,a2),max(a3,a4)) };
}
bool check(pair<double, double> p1, pair<double, double> p2)
{
	if (p1.first > p2.first) swap(p1, p2);
	return p2.first <= p1.second;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double l = 0, r = 1e9;
	int cnt = 1000;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		if (check(check(a, d, mid), check(b, c, mid))) r = mid;
		else l = mid;
	}
	printf("%.15f\n", l);
	return 0;
}