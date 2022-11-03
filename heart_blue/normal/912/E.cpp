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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
vector<int> v[2];
int cnt = 0;
LL maxv = 1e18;
vector<LL> ans[2];
void dfs(int cur, int o, LL pro = 1)
{
	if (cur == v[o].size())
	{
		ans[o].push_back(pro);
		return;
	}
	dfs(cur + 1, o, pro);
	if (pro <= maxv / v[o][cur])
		dfs(cur, o, pro * v[o][cur]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		v[i & 1].push_back(x);
	}
	dfs(0, 0);
	dfs(0, 1);
	LL k;
	scanf("%lld", &k);
	LL l = 1, r = 1e18;
	LL res = 0;
	auto& v0 = ans[0];
	auto& v1 = ans[1];
	sort(v0.begin(), v0.end());
	sort(v1.begin(), v1.end());
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		int ptr = v1.size() - 1;
		LL tot = 0;
		for (auto& x : v0)
		{
			while (ptr >= 0 && x > mid / v1[ptr])
				ptr--;
			tot += ptr + 1;
		}
		if (tot >= k) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", res);
	return 0;
}