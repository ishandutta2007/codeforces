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
const int N = 3e5 + 10;
int ans[N];
pair<int, int> a[N];
void solve(int n)
{
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		auto [l, r] = a[i];
		swap(l, r);
		l = -l;
		r = -r;
		a[i] = { l,r };
		mc[r]++;
		mc[l - 1] += 0;
	}
	int o = 0;
	for (auto& p : mc)
	{
		o += p.second;
		p.second = o;
	}
	for (int i = 1; i <= n; i++)
	{
		ans[i] += mc[a[i].first - 1];
	}
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i].first, &a[i].second);
			ans[i] = 0;
		}
		solve(n);
		solve(n);
		int res = INF;
		for (int i = 1; i <= n; i++)
			res = min(res, ans[i]);
		printf("%d\n", res);
	}
	return 0;
}