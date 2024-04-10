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
vector<int> v[N];
int flag[N];
bool dfs(int x, int o = 0)
{
	if (flag[x] != -1) return flag[x] == o;
	flag[x] = o;
	for (auto &y : v[x])
	{
		if (!dfs(y, o ^ 1))
			return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vp(m);
	MEM(flag, -1);
	for (auto &p : vp)
	{
		int x, y;
		cin >> x >> y;
		p = { x,y };
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (!dfs(1)) puts("NO"), exit(0);
	puts("YES");
	for (auto &p : vp) putchar('0' + flag[p.first]);
	return 0;
}