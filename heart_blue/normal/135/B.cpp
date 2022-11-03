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
class Point
{
public:
	int x, y;
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	Point operator - (const Point &p)
	{
		return Point(x - p.x, y - p.y);
	}
	int operator *(const Point &p)
	{
		return x*p.x + y*p.y;
	}
} p[N];
int check(Point p1, Point p2, Point p3, Point p4)
{
	if ((p2 - p1)*(p3 - p1) != 0) swap(p1, p2);
	if ((p2 - p1)*(p3 - p1) != 0) swap(p1, p3);
	if ((p2 - p1)*(p3 - p1) != 0) return 0;
	if ((p2 - p4)*(p3 - p4) != 0) return 0;
	if ((p2 - p1)*(p2 - p1) == (p3 - p1)*(p3 - p1)) return 3;
	else return 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 8;
	int a[8];
	for (int i = 0; i < 8; i++) a[i] = i;
	for (int i = 0; i < 8; i++) cin >> p[i].x >> p[i].y;
	do
	{
		int o1 = check(p[a[0]], p[a[1]], p[a[2]], p[a[3]]);
		int o2 = check(p[a[4]], p[a[5]], p[a[6]], p[a[7]]);
		if (o1 && o2 && (o1 | o2) == 3)
		{
			vector<int> ans;
			for (int i = 0; i < n; i++) ans.push_back(a[i] + 1);
			if (o1 == 1) reverse(ans.begin(), ans.end());
			cout << "YES" << endl;
			for (int i = 0; i < 4; i++) cout << ans[i] << ' ';
			cout << endl;
			for (int i = 4; i < 8; i++) cout << ans[i] << ' ';
			cout << endl;
			return 0;
		}
	} while (next_permutation(a, a + n));
	cout << "NO" << endl;
	return 0;
}