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
const int N = 1e6 + 10;

class Point
{
public:
	int a, b, c, d, e;
	Point(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->e = e;
	}
	void init()
	{
		cin >> a >> b >> c >> d >> e;
	}
	Point operator - (const Point &p)
	{
		return Point(a - p.a, b - p.b, c - p.c, d - p.d, e - p.e);
	}
	int operator * (const Point &p)
	{
		return a*p.a + b*p.b + c*p.c + d*p.d + e*p.e;
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n > 32)
	{
		cout << 0 << endl;
		return 0;
	}
	vector<Point> v(n);
	for (auto &p : v) p.init();
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			for (int k = 0; k < n; k++)
			{
				if (k == i || k == j) continue;
				if ((v[j] - v[i]) * (v[k] - v[i]) > 0)
				{
					flag = 0;
				}
			}
		}
		if (flag) ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}