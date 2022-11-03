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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

LL x[N];
LL y[N];
int n;
double dis(int i, int j)
{
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	return sqrt(dx*dx + dy*dy);
}
pair<int, int> check(int a)
{
	int k1 = 3, k2 = 3;
	int t = 2;
	double d1 = dis(t, 3) - dis(a, 3);
	double d2 = d1;

	for (int i = 4; i < n; i++)
	{
		long double tmp = dis(t, i) - dis(a, i);
		if (d1 == d2 || d2 < tmp) d2 = tmp, k2 = i;
		if (d1 < d2) swap(d1, d2), swap(k1, k2);
	}
	return{ k1,k2 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
	cin >> n;
	n += 3;
	for (int i = 3; i < n; i++) cin >> x[i] >> y[i];
	int a[2];
	int b[2];
	tie(a[0], a[1]) = check(0);
	tie(b[0], b[1]) = check(1);
	double ans = 0;
	int t = 2;
	for (int i = 3; i < n; i++)
	{
		ans += 2 * dis(2, i);
	}
	double tmp = -1e40;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tmp = max(tmp, dis(t, a[i]) - dis(0, a[i]));
			tmp = max(tmp, dis(t, b[j]) - dis(1, b[j]));
			if(a[i] != b[j])
				tmp = max(tmp, dis(t, a[i]) + dis(t, b[j]) - dis(0, a[i]) - dis(1, b[j]));
		}
	}
	printf("%.15f\n", ans - tmp);
	return 0;
}