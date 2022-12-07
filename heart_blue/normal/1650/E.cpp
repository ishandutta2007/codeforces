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
int solve(vector<int> v, int pos, int d)
{
	int key = v[pos];
	if (key == 0) return 0;
	int ans = 0;
	v.erase(v.begin() + pos);
	int minv1 = INF, minv2 = INF;
	for (int i = 0; i + 1 < v.size(); i++)
	{
		int x = v[i + 1] - v[i] - 1;
		if (x < minv2) minv2 = x;
		if (minv1 > minv2) swap(minv1, minv2);
	}
	if (v.back() != d) ans = max(ans, min(minv1, d - v.back() - 1));
	for (int i = 0; i + 1 < v.size(); i++)
	{
		int x = v[i + 1] - v[i] - 1;
		if (x == 0) continue;
		int res = 0;
		if (x == minv1) res = min(minv2, (x - 1) / 2);
		else res = min(minv1, (x - 1) / 2);
		ans = max(ans, res);
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, d;
		scanf("%d%d", &n, &d);
		vector<int> v(n);
		for (auto& x : v) scanf("%d", &x);
		v.insert(v.begin(), 0);
		vector<tuple<int, int, int>> vp;
		for (int i = 0; i + 1 < v.size(); i++)
		{
			vp.emplace_back(v[i + 1] - v[i], i, i + 1);
		}
		sort(vp.begin(), vp.end());
		int ans = 0;
		for (int i = 0; i < 4 && i < vp.size(); i++)
		{
			auto [w, x, y] = vp[i];
			ans = max(ans, solve(v, x, d));
			ans = max(ans, solve(v, y, d));
		}
		printf("%d\n", ans);
	}
	return 0;
}