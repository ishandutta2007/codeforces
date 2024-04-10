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
const int N = 5e3 + 10;
const double pi = acos(0.0) * 2;
double check(int x, int y)
{
	double r = sqrt(x*x + y*y);
	if (y == 0)
	{
		if (x > 0) return 0;
		else return pi;
	}
	if (y > 0)
	{
		return acos(x / r);
	}
	else
	{
		x = -x, y = -y;
		return acos(x / r) + pi;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<double> v;
	int n;
	cin >> n;
	//if (n == 1)
	//{
	//	puts("0.00000000000");
	//	return 0;
	//}
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(check(x, y));
	}
	sort(v.begin(), v.end());
	double ans = v.front() + 2 * pi - v.back();
	for (int i = 1; i < v.size(); i++) ans = max(ans, v[i] - v[i - 1]);
	printf("%.15f\n", (2 * pi - ans)/2/pi*360);
	return 0;
}