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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<LL> v(n);
		for (auto& x : v)
		{
			x = 0;
			for (int i = 0; i < m; i++)
			{
				LL y;
				scanf("%lld", &y);
				x += (m - i) * y;
			}
		}
		auto [minv, maxv] = minmax_element(v.begin(), v.end());
		printf("%d %lld\n", int(minv - v.begin() + 1), LL(*maxv - *minv));
	}
	return 0;
}