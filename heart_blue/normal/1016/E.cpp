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
const int N = 3e5 + 10;
vector<pair<double, double>> vp;
int sum[N];
double check(int x1, int y1, int x2, int y2)
{
	if (x1 == x2) return x1;
	else return -1.0*y1*(x2 - x1) / (y2 - y1) + x1;
}
double combine(double l1, double r1, double l2, double r2)
{
	return max(0.0, min(r2, r1) - max(l1, l2));
}
double getans(double x)
{
	int o = lower_bound(vp.begin(), vp.end(), make_pair(x, -1.0)) - vp.begin();
	return sum[o] + combine(vp[o].second, vp[o].first, 0, x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int sy, a, b;
	scanf("%d%d%d", &sy, &a, &b);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		sum[i + 1] = sum[i] + (r - l);
		vp.push_back({ 1.0*r,1.0*l });
	}
	vp.push_back({ 1.0*INF*INF,1.0*INF*INF });
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		double x1 = check(x, y, a, sy);
		double x2 = check(x, y, b, sy);
		double len = getans(x2) - getans(x1);
		printf("%.15f\n", len*(y - sy)/y);
	}
	return 0;
}