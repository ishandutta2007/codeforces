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
const int N = 5e2 + 10;
double p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	sort(p + 1, p + n + 1);
	double ans = 0;
	for (int i = n; i > 0; i--)
	{
		if (abs(1 - p[i]) <= 1e-7)
		{
			ans = 1;
			break;
		}
		if (p[i] < 1e-7) break;
		double o = 0;
		for (int j = i; j <= n; j++)
		{
			o += p[j] / (1 - p[j]);
		}
		for (int j = i; j <= n; j++)
		{
			o *= (1 - p[j]);
		}
		ans = max(ans, o);
	}
	printf("%.15f\n", ans);
	return 0;
}