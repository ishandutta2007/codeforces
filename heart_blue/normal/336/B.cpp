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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m;
	double r;
	cin >> m >> r;
	double ans = 2 * r;
	if (m > 1) ans += 2.0 * (m - 1) / m * (2 + sqrt(2)) * r;
	for (int i = 2; i < m; i++)
	{
		ans += 2.0 * (m - i) / m * (2 * sqrt(2) + 2 * (i - 1)) * r;
	}
	printf("%.15f\n", ans / m);
	return 0;
}