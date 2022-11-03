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
const int N = 5e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v1, v2;
		for (int i = 0; i < n * 2; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == 0) v2.push_back(abs(y));
			else v1.push_back(abs(x));
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			double x = v1[i];
			double y = v2[i];
			ans += sqrt(x * x + y * y);
		}
		printf("%.15f\n", ans);
	}

	return 0;
}