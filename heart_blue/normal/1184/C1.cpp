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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int p[N];
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int lx, ly, ux, uy;
	lx = INF, ly = INF;
	ux = -INF, uy = -INF;
	int n;
	cin >> n;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n * 4 + 1; i++)
	{
		int x, y;
		cin >> x >> y;
		vp.emplace_back(x, y);
		lx = min(lx, x);
		ly = min(ly, y);
		ux = max(ux, x);
		uy = max(uy, y);
	}
	for (int i = lx; i <= ux; i++)
	{
		for (int j = i; j <= ux; j++)
		{
			for (int s = ly; s <= uy; s++)
			{
				for (int t = s; t <= uy; t++)
				{
					vector<pair<int, int>> ans;
					for (auto& p : vp)
					{
						int x, y;
						tie(x, y) = p;
						if ((x >= i && x <= j && y >= s && y <= t) &&
							(x == i || x == j || y == s || y == t)) continue;
						ans.emplace_back(x, y);
					}
					if (ans.size() == 1)
					{
						int x, y;
						tie(x, y) = ans.back();
						cout << x << ' ' << y << endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}