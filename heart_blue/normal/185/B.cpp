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
const int N = 3e3 + 10;
double getans(int a, int b, double s1, double s2)
{
	double ret = 0;
	if (a != 0) ret += a * log(s1);
	if (b != 0) ret += b * log(s2);
	return ret;
}
double getans(int a, int b, int c, double s1, double s2, double s3)
{
	double ret = 0;
	if (a != 0) ret += a * log(s1);
	if (b != 0) ret += b * log(s2);
	if (c != 0) ret += c * log(s3);
	return ret;
}
double check(int a, int b, double s)
{
	double l = 0, r = s;
	int cnt = 500;
	while (cnt--)
	{
		double mid1 = (l + r) / 2;
		double mid2 = (mid1 + r) / 2;
		double lans = getans(a, b, mid1, s - mid1);
		double rans = getans(a, b, mid2, s - mid2);
		if (lans < rans) l = mid1;
		else r = mid2;
	}
	return l;
}
double ans[4];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int s;
	int a, b, c;
	cin >> s >> a >> b >> c;
	vector<pair<int, int>> vp;
	vp.emplace_back(a, 1);
	vp.emplace_back(b, 2);
	vp.emplace_back(c, 3);
	sort(vp.rbegin(), vp.rend());
	a = vp[0].first;
	b = vp[1].first;
	c = vp[2].first;
	if (a == 0 && b == 0 && c == 0)
	{
		puts("0.1 0.1 0.1");
		return 0;
	}
	double l1 = 0, r1 = s;
	int cnt1 = 500;
	while (cnt1--)
	{
		double mid1 = (l1 + r1) / 2;
		double mid2 = (mid1 + r1) / 2;
		double sb1 = check(b, c, s - mid1), sb2 = check(b, c, s - mid2);
		double lans = getans(a, b, c, mid1, sb1, s - mid1 - sb1);
		double rans = getans(a, b, c, mid2, sb2, s - mid2 - sb2);
		if (lans < rans) l1 = mid1;
		else r1 = mid2;
	}
	double x = l1;
	double y = check(b, c, s - x);
	double z = s - x - y;
	ans[vp[0].second] = x;
	ans[vp[1].second] = y;
	ans[vp[2].second] = z;
	tie(x, y, z) = make_tuple(ans[1], ans[2], ans[3]);
	printf("%.15f %.15f %.15f\n", x, y, z);
	return 0;
}