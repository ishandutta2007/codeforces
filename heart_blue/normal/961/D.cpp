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
const int N = 1e5 + 10;
class Point
{
public:
	LL x, y;
	Point(LL x = 0, LL y = 0)
	{
		this->x = x;
		this->y = y;
	}
	Point operator - (Point p)
	{
		return Point(x - p.x, y - p.y);
	}
};
bool check(Point p1, Point p2)
{
	return p1.x*p2.y == p1.y*p2.x;
}
Point vp[N];
int flag[N];
int n;
bool check(int k1, int k2)
{
	MEM(flag, 0);
	Point pp = vp[k2] - vp[k1];
	vector<int> v;
	flag[k2] = flag[k1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		if (!check(pp, vp[i] - vp[k1])) v.push_back(i);
		else flag[i] = 1;
	}
	if (v.size() <= 2) return true;
	Point ppp = vp[v[1]] - vp[v[0]];
	flag[v[1]] = flag[v[0]] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		if (!check(ppp, vp[i] - vp[v[0]]))
			return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	if (n <= 4)
	{
		puts("YES");
		return 0;
	}
	MEM(flag, 0);
	for (int i = 1; i <= n; i++) cin >> vp[i].x >> vp[i].y;
	if (check(1,2) || check(1,3) || check(2,3)) puts("YES");
	else puts("NO");
	return 0;
}