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
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, h;
	scanf("%d%d%d", &n, &k, &h);
	vector<tuple<int, int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		vp.emplace_back(0, 0, i);
	}
	for (auto& [m, v, id] : vp)
		scanf("%d", &m);
	for (auto& [m, v, id] : vp)
		scanf("%d", &v);
	vector<int> ans;
	sort(vp.begin(), vp.end());
	double l = 0, r = 1e10;
	int cnt = 100;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		vector<int> tmp;
		for (auto& [m, v, id] : vp)
		{
			if (tmp.size() == k) break;
			int cur = tmp.size() + 1;
			if (cur * h <= mid * v)
			{
				tmp.push_back(id);
			}
		}
		if (tmp.size() == k) ans = tmp, r = mid;
		else l = mid;
	}
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}