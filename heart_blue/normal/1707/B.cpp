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
void check(map<int, int>& mc)
{
	if (mc.size() == 1)
	{
		auto [x, cnt] = *mc.begin();
		mc.clear();
		if (cnt == 1) mc[x] = 1;
		else mc[0] = 1;
		return;
	}
	vector<pair<int, int>> vp;
	for (auto& p : mc)
		vp.push_back(p);
	mc.clear();
	for (auto& p : vp)
	{
		if (p.second > 1)
			mc[0] += p.second - 1;
	}
	for (int i = 1; i < vp.size(); i++)
		mc[vp[i].first - vp[i - 1].first]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int pre = -1;
		map<int, int> mc;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			int x;
			scanf("%d", &x);
			if (pre != -1) mc[x - pre]++;
			pre = x;
		}
		while (mc.size() > 1)
			check(mc);
		check(mc);
		printf("%d\n", mc.begin()->first);
	}
	return 0;
}