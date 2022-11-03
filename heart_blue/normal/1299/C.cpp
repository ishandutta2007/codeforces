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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<LL, int>> vp;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		LL x;
		scanf("%lld", &x);
		int sz1 = 1;
		while (!vp.empty())
		{
			auto [y, sz2] = vp.back();
			if (y * sz1 >= x * sz2)
			{
				vp.pop_back();
				x += y;
				sz1 += sz2;
			}
			else
				break;
		}
		vp.emplace_back(x, sz1);
	}
	for (auto& [x, sz] : vp)
	{
		for (int i = 1; i <= sz; i++)
		{
			printf("%.15f\n", 1.0 * x / sz);
		}
	}
	return 0;
}