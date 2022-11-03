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
const int N = 3e5 + 10;
pair<int, int> p[N];
int sz;
bool check(int x1, int y1, int x2, int y2)
{
	return x1 == x2 || y1 == y2;
}
void dfs(int cur, int x, int y = 0)
{
	if (cur > sz)
	{
		puts("YES");
		exit(0);
	}
	if (check(p[cur].first, p[cur].second, x, y) ||
		check(p[cur].first, p[cur].second, y, x))
	{
		dfs(cur + 1, x, y);
	}
	else
	{
		if (y == 0)
		{
			dfs(cur, x, p[cur].first);
			dfs(cur, x, p[cur].second);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%*d%d", &sz);
	for (int i = 1; i <= sz; i++) scanf("%d%d", &p[i].first, &p[i].second);
	dfs(1, p[1].first);
	dfs(1, p[1].second);
	puts("NO");
	return 0;
}