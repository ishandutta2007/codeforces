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
	vector<int> vp;
	int n, k;
	cin >> n >> k;
	while (n--)
	{
		int x;
		cin >> x;
		while (vp.size() >= 2 && vp[vp.size() - 2] + k >= x) vp.pop_back();
		if (!vp.empty())
		{
			if (x - vp.back() > k)
			{
				puts("-1");
				return 0;
			}
		}
		vp.push_back(x);
	}
	cout << vp.size() - 1 << endl;
	return 0;
}