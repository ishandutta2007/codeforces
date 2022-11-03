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
const int N = 2e2 + 10;
const double eps = 1e-10;
inline int dcmp(const double x)
{
	if (abs(x) <= eps) return 0;
	else return x > 0 ? 1 : -1;
}
inline int dcmp(const double x, const double y)
{
	return dcmp(x - y);
}
double dfs(double cur, double c, double m, double p, double v, int cnt = 1)
{
	double ret = cnt * p * cur;
	if (dcmp(c) >= 0)
	{
		if (dcmp(c, v) <= 0)
			ret += dfs(cur * c, -INF, m + c / 2, p + c / 2 + (m < 0 ? c / 2 : 0), v, cnt + 1);
		else
			ret += dfs(cur * c, c - v, m + v / 2, p + v / 2 + (m < 0 ? v / 2 : 0), v, cnt + 1);
	}
	if (dcmp(m) >= 0)
	{
		if (dcmp(m, v) <= 0)
			ret += dfs(cur * m, c + m / 2, -INF, p + m / 2 + (c < 0 ? m / 2 : 0), v, cnt + 1);
		else
			ret += dfs(cur * m, c + v / 2, m - v, p + v / 2 + (c < 0 ? v / 2 : 0), v, cnt + 1);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		double c, m, p, v;
		scanf("%lf%lf%lf%lf", &c, &m, &p, &v);
		printf("%.15f\n", dfs(1, c, m, p, v, 1));
	}
	return 0;
}