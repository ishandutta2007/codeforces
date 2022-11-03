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
map<tuple<int, int, int, int>, int> mc;
int check(int a, int b, int c, int d)
{
	if (make_pair(a, b) > make_pair(c, d))
		swap(a, c), swap(b, d);
	auto p = make_tuple(a, b, c, d);
	int ret = 5;
	if (mc.count(p)) ret = 1;
	mc[p] = 1;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string str;
		cin >> str;
		int x = 0, y = 0;
		int ans = 0;
		mc.clear();
		for (auto& c : str)
		{
			int tx = x, ty = y;
			if (c == 'N') tx++;
			if (c == 'S') tx--;
			if (c == 'W') ty++;
			if (c == 'E') ty--;
			ans += check(x, y, tx, ty);
			x = tx, y = ty;
		}
		printf("%d\n", ans);
	}
	return 0;
}