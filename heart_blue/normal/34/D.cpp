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
int p[N];
vector<int> v[N];
void dfs(int x, int fa = -1)
{
	if (fa != -1) p[x] = fa;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, r1, r2;
	cin >> n >> r1 >> r2;
	for (int i = 1; i <= n; i++)
	{
		if (i == r1) continue;
		int x;
		cin >> x;
		v[x].push_back(i);
		v[i].push_back(x);
	}
	dfs(r2);
	for (int i = 1; i <= n; i++)
	{
		if (i == r2) continue;
		cout << p[i] << ' ';
	}
	return 0;
}