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
const int N = 1e5 + 10;
pair<int, int> p[N];
int n;
inline double dis(double ax, double ay, double bx, double by)
{
	double dx = ax - bx;
	double dy = ay - by;
	return sqrt(dx * dx + dy * dy);
}
double check(double x)
{
	double maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		double d1 = dis(p[i].first, p[i].second, x, 0);
		double d2 = dis(0, 1, 0, 0);
		double dot = p[i].second;
		double cosa = dot / d1 / d2;
		maxv = max(maxv, d1 / 2 / cosa);
	}
	return maxv;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	double l = -INF, r = INF;
	int flag = 0;
	int pos = 0;
	int neg = 0;
	int zero = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &p[i].first, &p[i].second);
		if (p[i].second > 0) pos = 1;
		else if (p[i].second < 0) neg = 1;
	}
	if (pos > 0 && neg > 0)
	{
		puts("-1");
		return 0;
	}
	if (neg)
	{
		for (int i = 1; i <= n; i++)
		{
			p[i].second = -p[i].second;
		}
	}
	int cnt = 300;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		double midmid = (mid + r) / 2;
		double res1 = check(mid);
		double res2 = check(midmid);
		if (res1 > res2) l = mid;
		else r = midmid;
		//cout << l << ' ' << r << endl;
	}
	printf("%.15f\n", check(l));
	return 0;
}