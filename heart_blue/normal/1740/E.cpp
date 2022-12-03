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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int maxlen[N];
int ans[N];
void dfs(int x)
{
	ans[x] = 0;
	for (auto& y : v[x])
	{
		dfs(y);
		ans[x] += ans[y];
		maxlen[x] = max(maxlen[x], maxlen[y]);
	}
	maxlen[x]++;
	ans[x] = max(maxlen[x], ans[x]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		v[p].push_back(i);
	}
	dfs(1);
	printf("%d\n", ans[1]);
	return 0;
}