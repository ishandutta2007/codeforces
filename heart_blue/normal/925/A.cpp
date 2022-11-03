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
int solve(int x1, int y1, int x2, int y2, int y, int v)
{
	return abs(y1 - y) + abs(y2 - y) + (abs(x2 - x1) - 1 + v) / v;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k1, k2, v;
	cin >> n >> m >> k1 >> k2 >> v;
	vector<int> v1, v2;
	v1.push_back(-5e8);
	v2.push_back(-5e8);
	for (int i = 1; i <= k1; i++)
	{
		int x;
		cin >> x;
		v1.push_back(x);
	}
	for (int i = 1; i <= k2; i++)
	{
		int x;
		cin >> x;
		v2.push_back(x);
	}
	v1.push_back(5e8);
	v2.push_back(5e8);
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
		{
			cout << abs(y1 - y2) << '\n';
			continue;
		}
		int o1 = lower_bound(v1.begin(), v1.end(), y1) - v1.begin();
		int o2 = lower_bound(v2.begin(), v2.end(), y1) - v2.begin();
		int ans1 = min(solve(x1, y1, x2, y2, v1[o1], 1), solve(x1, y1, x2, y2, v1[o1 - 1], 1));
		int ans2 = min(solve(x1, y1, x2, y2, v2[o2], v), solve(x1, y1, x2, y2, v2[o2 - 1], v));
		cout << min(ans1, ans2) << '\n';
	}
	return 0;
}