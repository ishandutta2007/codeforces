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
LL a[N];
LL add(LL x, LL y)
{
	if (x + y >= INF * INF) return INF * INF;
	else return x + y;
}
bool dfs(int x, LL key, LL &need)
{
	if (v[x].empty())
	{
		need = key - a[x];
		return a[x] <= key;
	}
	LL tot = 0;
	for (auto& y : v[x])
	{
		LL tmp = 0;
		if (!dfs(y, key, tmp)) return false;
		tot = add(tot, tmp);
	}
	need = tot - a[x];
	return a[x] <= tot;
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
	int cnt = 0;
	LL l = 0, r = INF * INF;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	LL ans = 0;
	LL tmp = 0;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (dfs(1, mid, tmp)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}