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
const int N = 5e5 + 10;
int nex[N + 10][20];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);

	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l++;
		vp.emplace_back(l, r);
	}
	sort(vp.rbegin(), vp.rend());
	int cur = 0;
	for (int i = 1; i <= N; i++)
	{
		while (!vp.empty() && vp.back().first == i)
		{
			cur = max(cur, vp.back().second);
			vp.pop_back();
		}
		if (cur >= i) nex[i][0] = cur;
	}
	for (int i = N; i >= 1; i--)
	{
		if (nex[i][0] == 0) continue;
		int r = nex[i][0] + 1;
		for (int o = 1; o < 20; o++)
		{
			int r = nex[i][o - 1] + 1;
			nex[i][o] = nex[r][o - 1];
			if (nex[i][o] == 0)
				nex[i][o] = nex[i][o - 1];
		}
	}
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l++;
		if (nex[l][19] < r)
		{
			puts("-1");
			continue;
		}
		int ans = 0;
		for (int i = 19; i >= 0; i--)
		{
			if (nex[l][i] < r)
			{
				ans += 1 << i;
				l = nex[l][i] + 1;
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}