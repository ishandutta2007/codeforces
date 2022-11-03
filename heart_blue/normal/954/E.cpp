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
const int N = 2e3 + 10;
double solve(vector<pair<int, int>>& vp)
{
	LL sum = 0;
	for (auto& p : vp)
	{
		p.first = -p.first;
		sum += p.second;
	}
	sort(vp.begin(), vp.end());
	if (vp.front().first > 0 || vp.back().first < 0) return 0;
	double l = 0, r = sum;
	int cnt = 150;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		double tot = mid;
		double cost = 0;
		for (auto& p : vp)
		{
			double o = min(tot, 1.0 * p.second);
			cost += o * p.first;
			tot -= o;
			if (tot < 1e-9) break;
		}
		if (cost / mid > 0) r = mid;
		else l = mid;
	}
	return l;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int T;
	scanf("%d%d", &n, &T);
	vector<pair<int, int>> vp(n);
	for (auto& [t, a] : vp)
		scanf("%d", &a);
	for (auto& [t, a] : vp)
	{
		scanf("%d", &t);
		t -= T;
	}
	printf("%.15f\n", min(solve(vp), solve(vp)));
	return 0;
}