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
pair<int, int> p[N];
vector<int> v[N];
LL w[N];
int ans = 0;
void dfs(int x)
{
	auto [l, r] = p[x];
	if (v[x].empty())
	{
		ans++;
		w[x] = r;
		return;
	}
	LL tot = 0;
	for (auto& y : v[x])
	{
		dfs(y);
		tot += w[y];
	}
	if (l > tot) ans++, w[x] = r;
	else w[x] = min(tot, r * 1LL);
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
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &p[i].first, &p[i].second);
		ans = 0;
		dfs(1);
		printf("%d\n", ans);

	}
	return 0;
}