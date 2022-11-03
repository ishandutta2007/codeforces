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
const int N = 2e3 + 10;
int a, b;
struct Point
{
	int x, y;
	void swap()
	{
		::swap(x, y);
	}
	int sum()
	{
		return x*y;
	}
} p[N];
bool check(Point p1, Point p2)
{
	if (p1.x + p2.x <= a)
	{
		return max(p1.y, p2.y) <= b;
	}
	if (p1.y + p2.y <= b)
	{
		return max(p1.x, p2.x) <= a;
	}
	return p1.x + p2.x <= a && p1.y + p2.y <= b;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int o = 0; o < 2; o++)
			{
				for (int s = 0; s < 2; s++)
				{
					if (check(p[i], p[j]))
					{
						ans = max(ans, p[i].sum() + p[j].sum());
					}
					p[j].swap();
				}
				p[i].swap();
			}
		}
	}
	cout << ans << endl;
	return 0;
}