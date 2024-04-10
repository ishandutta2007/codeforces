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
double dis(double x1, double y1, double x2, double y2, double alpha)
{
	double x = x1 + (x2 - x1)*alpha;
	double y = y1 + (y2 - y1)*alpha;
	return x * x + y * y;
}
double check(double x1, double y1, double x2, double y2)
{
	double l = 0, r = 1;
	int cnt = 300;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		double midmid = (mid + r) / 2;
		if (dis(x1, y1, x2, y2, mid) > dis(x1, y1, x2, y2, midmid)) l = mid;
		else r = midmid;
	}
	return dis(x1, y1, x2, y2, l);
}
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x, y;
	cin >> n >> x >> y;
	vp.resize(n);
	LL R = 0;
	double r = 1e18;
	for (auto &p : vp)
	{
		int ox, oy;
		cin >> ox >> oy;
		ox -= x;
		oy -= y;
		p = { ox,oy };
		R = max(1LL * ox*ox + 1LL * oy*oy, R);
	}
	vp.push_back(vp[0]);
	for (int i = 0; i < n; i++)
	{
		r = min(r, check(vp[i].first, vp[i].second, vp[i + 1].first, vp[i + 1].second));
	}
	printf("%.15f\n", acos(0.0) * 2 * (R - r));

	return 0;
}