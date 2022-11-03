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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp(n);
	double ans = 0;
	for (auto& [l, p] : vp)
	{
		scanf("%d%d", &l, &p);
		ans += l;
	}
	sort(vp.begin(), vp.end(), [](pair<int, int>& a, pair<int, int>& b) -> bool
		{
			auto [len1, p1] = a;
			auto [len2, p2] = b;
			return p1 * (100 - p2) * len1 > (100 - p1) * p2 * len2;
		});
	double sum = 0;
	for (auto& [l, p] : vp)
	{
		ans += sum * (1 - p / 100.0);
		sum += l * p / 100.0;
	}
	printf("%.15f\n", ans);
	return 0;

}