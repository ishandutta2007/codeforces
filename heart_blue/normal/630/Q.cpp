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
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double pi = acos(0.0) * 2;
	double ans = 0;
	for (int i = 3; i <= 5; i++)
	{
		double x;
		cin >> x;
		double alpha = pi / i;
		double r = x / 2 / sin(alpha);
		double h = sqrt(x * x - r * r);
		double s = 0.5 * r * r * sin(alpha * 2) * i;
		ans += s * h / 3;
	}
	printf("%.15f\n", ans);
	return 0;
}