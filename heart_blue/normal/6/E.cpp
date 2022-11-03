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
const int N = 1e5 + 10;
int maxv[N][20];
int minv[N][20];
int cnt[N];
void init(int n)
{
	cnt[0] = 0;
	for (int i = 1; i <= n; i++) cnt[i] = cnt[i >> 1] + 1;
	for (int o = 0; (1 << o) <= n; o++)
	{
		for (int i = 1; i + (2 << o) <= n + 1; i++)
		{
			minv[i][o + 1] = min(minv[i][o], minv[i + (1 << o)][o]);
			maxv[i][o + 1] = max(maxv[i][o], maxv[i + (1 << o)][o]);
		}
	}
}
int solve(int l, int r)
{
	int o = cnt[r - l + 1] - 1;
	return max(maxv[l][o], maxv[r - (1 << o) + 1][o]) -
		min(minv[l][o], minv[r - (1 << o) + 1][o]);
}
vector<pair<int, int>> ans;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &minv[i][0]);
		maxv[i][0] = minv[i][0];
	}
	init(n);
	int a = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n;
		int ret = i;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (solve(i, mid) <= k) ret = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (ret - i + 1 > a)
		{
			a = ret - i + 1;
			ans.clear();
		}
		if (ret - i + 1 == a) ans.push_back({ i, ret });
	}
	printf("%d %d\n", a, ans.size());
	for (auto &p : ans) printf("%d %d\n", p.first, p.second);
	return 0;
}