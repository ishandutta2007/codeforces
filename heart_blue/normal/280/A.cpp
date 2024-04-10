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
const int N = 2e4 + 10;
const double pi = acos(0.0) * 2;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double w, h;
	double alpha;
	cin >> w >> h >> alpha;
	if (alpha == 90)
	{
		printf("%.15f\n", min(w, h) * min(w, h));
		return 0;
	}
	if (alpha >= 90) alpha = 180 - alpha;
	if (alpha == 0)
	{
		printf("%.15f\n", w * h);
		return 0;
	}
	if (w < h) swap(w, h);
	double theta = 2 * atan2(h, w);
	alpha /= (180 / pi);
	if (alpha <= theta)
	{
		double t = 1 / sin(alpha) + 1 / tan(alpha);
		/*
		tx + y = w;
		x + ty = h;
		x+y = (w+h)/(t+1);
		*/
		double o = (w + h) / (t + 1);
		double y = (h - o) / (t - 1);
		double x = o - y;
		printf("%.15f\n", w * h - (x * x + y * y) / tan(alpha));
	}
	else
	{
		printf("%.15f\n", h * h / sin(alpha));
	}
	return 0;
}