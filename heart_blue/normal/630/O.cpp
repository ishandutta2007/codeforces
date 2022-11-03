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
	vector<pair<double, double>> vp;
	double px, py, vx, vy;
	double a, b, c, d;
	cin >> px >> py >> vx >> vy;
	cin >> a >> b >> c >> d;
	vp.emplace_back(0, b);
	vp.emplace_back(-a / 2, 0);
	vp.emplace_back(-c / 2, 0);
	vp.emplace_back(-c / 2, -d);
	vp.emplace_back(c / 2, -d);
	vp.emplace_back(c / 2, 0);
	vp.emplace_back(a / 2, 0);
	double alpha = atan2(vy, vx);
	alpha -= acos(0.0);
	for (auto& p : vp)
	{
		double x, y;
		tie(x, y) = p;
		tie(x, y) = make_pair(x * cos(alpha) - y * sin(alpha)
		,x*sin(alpha)+y*cos(alpha));
		printf("%.15f %.15f\n", x + px, y + py);
	}
	return 0;
}