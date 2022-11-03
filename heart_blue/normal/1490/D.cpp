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
const int N = 1e2 + 10;
int a[N];
int ans[N];
void dfs(int l, int r, int depth = 0)
{
	if (l > r) return;
	int key = l;
	for (int i = l; i <= r; i++)
	{
		if (a[i] > a[key])
			key = i;
	}
	ans[key] = depth;
	dfs(l, key - 1, depth + 1);
	dfs(key + 1, r, depth + 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		dfs(1, n);
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);

	}
	return 0;
}