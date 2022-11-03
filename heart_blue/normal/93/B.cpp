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
const int N = 2e2 + 10;
vector<pair<int,int>> ans[N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, w, m;
	cin >> n >> w >> m;
	int cost = n * w;
	w = w * m;
	int cur = w;
	int o = 1;
	for (int i = 1; i <= m; i++)
	{
		int rest = cost;
		while (rest >= cur)
		{
			rest -= cur;
			ans[i].emplace_back(o, cur);
			if(cnt[o]++ == 2) puts("NO"),exit(0);
			o++;
			cur = w;
		}
		if (cur == 0) cur = w, o++;
		if (rest > 0)
		{
			cur -= rest;
			ans[i].emplace_back(o, rest);
			if (cnt[o]++ == 2) puts("NO"), exit(0);
		}
	}
	puts("YES");
	for (int i = 1; i <= m; i++)
	{
		for (auto& p : ans[i])
		{
			printf("%d %.15f ", p.first, p.second * 1.0 / m);
		}
		puts("");
	}

	return 0;
}