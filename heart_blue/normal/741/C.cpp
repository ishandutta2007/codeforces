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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int col[N];
void dfs(int x, int o = 0)
{
	if (col[x] >= 0) return;
	col[x] = o;
	for (auto &y : v[x])
	{
		dfs(y, o ^ 1);
	}
}
vector<pair<int, int>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		vp.push_back({ x,y });
		v[i * 2 - 1].push_back(i * 2);
		v[i * 2].push_back(i * 2 - 1);
	}
	MEM(col, -1);
	for (int i = 1; i <= 2 * n; i++)
	{
		if (col[i] >= 0) continue;
		dfs(i);
	}
	for (auto &p : vp)
	{
		printf("%d %d\n", col[p.first] + 1, col[p.second] + 1);
	}
	return 0;
}