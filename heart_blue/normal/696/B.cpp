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
int son[N];
double ans[N];
void dfs1(int x)
{
	son[x] = 1;
	for (auto &y : v[x])
	{
		dfs1(y);
		son[x] += son[y];
	}
}
void dfs2(int x, int fa = -1)
{
	ans[x] = 1;
	if (fa != -1) ans[x] += ans[fa] + (son[fa] - son[x] - 1)*0.5;
	for (auto &y : v[x])
	{
		dfs2(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	for (int i = 1; i <= n; i++) printf("%.1f ", ans[i]);
	return 0;
}