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
const int N = 1e5 + 10;
int a[N];
int b[N];
int posa[N];
int posb[N];
int cur[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		posa[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		posb[b[i]] = i;
	}
	set<pair<int, int>> sp;
	for (int i = 1; i <= n; i++)
	{
		cur[i] = posb[i] - posa[i];
		sp.emplace(cur[i], i);
	}
	fill(ans + 1, ans + n + 1, n);
	for (int i = 1; i <= n; i++)
	{
		int o = i - 1;
		auto iter = sp.lower_bound(make_pair(o, -1));
		if (iter != sp.end())
		{
			ans[i] = min(ans[i], abs(iter->first - o));
		}
		if (iter != sp.begin())
		{
			iter--;
			ans[i] = min(ans[i], abs(iter->first - o));
		}
		int x = b[i];
		sp.erase(make_pair(cur[x], x));
		cur[x] = n - posa[x] + i;
		sp.emplace(cur[x], x);
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;

}