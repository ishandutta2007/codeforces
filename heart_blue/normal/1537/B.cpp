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
LL dis(int a, int b, int c, int d)
{
	return abs(c - a) + abs(d - b);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, x, y;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		vector<pair<int, int>> vp;
		vp.emplace_back(1, 1);
		vp.emplace_back(1, m);
		vp.emplace_back(n, 1);
		vp.emplace_back(n, m);
		tuple<LL, int, int> ans = { 0,0,0 };
		for (int i = 0; i < vp.size(); i++)
		{
			for (int j = i + 1; j < vp.size(); j++)
			{
				ans = max(ans, { dis(x, y, vp[i].first, vp[i].second) +
					dis(vp[i].first, vp[i].second, vp[j].first, vp[j].second) +
					dis(vp[j].first, vp[j].second, x, y), i,j });
			}
		}
		int id1, id2;
		tie(ignore, id1, id2) = ans;
		printf("%d %d %d %d\n", vp[id1].first, vp[id1].second, vp[id2].first, vp[id2].second);
	}
	return 0;
}