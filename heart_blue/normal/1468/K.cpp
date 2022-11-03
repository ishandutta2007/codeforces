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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<pair<int, int>> vp;
		string str;
		int x = 0, y = 0;
		cin >> str;
		for (auto& c : str)
		{
			if (c == 'L') x -= 1;
			if (c == 'R') x += 1;
			if (c == 'D') y -= 1;
			if (c == 'U') y += 1;
			vp.emplace_back(x, y);
		}
		int rx = 0, ry = 0;
		for (auto& [kx,ky] : vp)
		{
			int x = 0, y = 0;
			for (auto& c : str)
			{
				int tx = x, ty = y;
				if (c == 'L') tx -= 1;
				if (c == 'R') tx += 1;
				if (c == 'D') ty -= 1;
				if (c == 'U') ty += 1;
				if (tx == kx && ty == ky) continue;
				x = tx, y = ty;
			}
			if (x == 0 && y == 0)
			{
				rx = kx, ry = ky;
				break;
			}
		}
		printf("%d %d\n", rx, ry);
	}
	return 0;
}