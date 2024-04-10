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
const double eps = 1e-8;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, v1, v2, k;
	double l;
	cin >> n >> l >> v1 >> v2 >> k;
	auto check = [=](double x) -> bool
	{
		int tot = (n - 1) / k;
		double len = l;
		while (tot--)
		{
			double s = (x*v1 - len)*v2 / (v1 - v2);
			double cost = 2 * s / (v1 + v2);
			len -= v1*cost;
			x -= cost;
		}
		return len / v2 <= x;
	};
	double L = 0, R = l / v1;
	int cnt = 100;
	while (R - L > eps && cnt--)
	{
		double mid = (R + L) / 2;
		if (check(mid)) R = mid;
		else L = mid;
	}
	printf("%.15f\n", L);
	return 0;
}