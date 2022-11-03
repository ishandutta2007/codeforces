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
int sz[N];
vector<int> v[N];
vector<int> ans;
void dfs(int x, int d = 1, int fa = 0)
{
	sz[x] = 1;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, d + 1, x);
		sz[x] += sz[y];
	}
	ans.push_back(d - sz[x]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	sort(ans.rbegin(), ans.rend());
	LL sum = 0;
	for (int i = 0; i < k; i++)
		sum += ans[i];
	printf("%lld\n", sum);
	return 0;
}