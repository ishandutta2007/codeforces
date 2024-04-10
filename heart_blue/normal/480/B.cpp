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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
bool check(vector<int> &v, int x)
{
	for (auto &o : v)
	{
		int t = lower_bound(v.begin(), v.end(), o + x) - v.begin();
		if (t < v.size() && v[t] == o + x)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l, x, y;
	cin >> n >> l >> x >> y;
	vector<int> v(n);
	for (auto &o : v) cin >> o;
	int flag1 = 0, flag2 = 0;
	flag1 = check(v, x);
	flag2 = check(v, y);
	if (flag1 || flag2)
	{
		if (flag1 == flag2)
		{
			cout << 0 << endl;
		}
		else
		{
			if (!flag1) cout << 1 << endl <<  x << endl;
			else cout << 1 << endl << y << endl;
		}
		return 0;
	}
	for (auto o : v)
	{
		int o1, o2, o3, o4;
		o1 = o2 = o3 = o4 = n;
		if (o + x <= l)
		{
			o1 = lower_bound(v.begin(), v.end(), o + x + y) - v.begin();
			o2 = lower_bound(v.begin(), v.end(), o + x - y) - v.begin();
		}
		if (o - x >= 0)
		{
			o3 = lower_bound(v.begin(), v.end(), o - x + y) - v.begin();
			o4 = lower_bound(v.begin(), v.end(), o - x - y) - v.begin();
		}
		if ((o1 < v.size() && v[o1] == o + x + y) ||
			(o2 < v.size() && v[o2] == o + x - y))
		{
			cout << 1 << endl << o + x << endl;
			return 0;
		}
		if ((o3 < v.size() && v[o3] == o - x + y) ||
			(o4 < v.size() && v[o4] == o - x - y))
		{
			cout << 1 << endl << o - x << endl;
			return 0;
		}
	}
	cout << 2 << endl;
	cout << x << endl;
	cout << y << endl;
	return 0;
}