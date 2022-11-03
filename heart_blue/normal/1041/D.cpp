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
const int N = 4e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, h;
	scanf("%d%d", &n, &h);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp.emplace_back(x, y);
	}
	vp.emplace_back(int(INF * 2), int(INF * 2));
	int tot = h;
	int pos = 0;
	int ptr = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ptr = max(i + 1, ptr);
		pos = max(pos, vp[i].second);
		pos += tot;
		while (ptr <= n && pos > vp[ptr].first)
		{
			pos += vp[ptr].second - vp[ptr].first;
			ptr++;
		}
		ans = max(ans, pos - vp[i].first);
		tot = min(h, vp[i + 1].first - vp[i].second);
	}
	printf("%d\n", ans);
	return 0;
}