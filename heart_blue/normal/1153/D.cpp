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
const int N = 3e5 + 10;
int flag[N];
vector<int> v[N];
int sz[N];
int dfs(int x)
{
	if (v[x].empty())
	{
		sz[x] = 1;
		return 1;
	}
	int l = 0, r = INF;
	for (auto& y : v[x])
	{
		int k = dfs(y);
		sz[x] += sz[y];
		l += k - 1;
		r = min(r, sz[y] - k);
	}
	if (flag[x] == 0) return l + 1;
	else return sz[x] - r;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &flag[i]);
	for (int i = 2; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		v[p].push_back(i);
	}
	printf("%d\n", dfs(1));
	return 0;
}