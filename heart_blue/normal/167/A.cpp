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
const int N = 2e5 + 10;
double ans[N];
double getans(double v, double a, double s)
{
	double t = v / a;
	double d = 0.5*a*t*t;
	if (d >= s) return sqrt(2 * s/a);
	else return t + (s - d) / v;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ans[0] = 0;
	int n, a, d;
	cin >> n >> a >> d;
	for (int i = 1; i <= n; i++)
	{
		int t, v;
		cin >> t >> v;
		ans[i] = max(ans[i - 1], t + getans(v, a, d));
		printf("%.15f\n", ans[i]);
	}
	return 0;
}