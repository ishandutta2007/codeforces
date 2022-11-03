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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		int lx, rx, ly, ry;
		lx = ly = -1e5;
		rx = ry = 1e5;
		while (n--)
		{
			int a, b, c, d;
			int x, y;
			cin >> x >> y;
			cin >> a >> b >> c >> d;
			if (!a) lx = max(lx, x);
			if (!c) rx = min(rx, x);
			if (!d) ly = max(ly, y);
			if (!b) ry = min(ry, y);
		}
		if (lx > rx || ly > ry) puts("0");
		else printf("1 %d %d\n", lx, ly);
	}
	return 0;
}