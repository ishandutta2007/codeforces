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
const int N = 1e4 + 10;
int dp[N];
int res[N];
int init(vector<tuple<int, int, int>>& vp)
{
	vector<int> v;
	for (auto [a, b, i] : vp)
	{
		v.push_back(a);
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto& [a, b, i] : vp)
	{
		a = lower_bound(v.begin(), v.end(), a) - v.begin() + 1;
		b = lower_bound(v.begin(), v.end(), b) - v.begin() + 1;
		a = b - a;
	}
	sort(vp.begin(), vp.end());
	return v.size();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(res, 0);
		int n;
		scanf("%d", &n);
		vector<tuple<int, int, int>> vp;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			vp.emplace_back(a, b, i);
		}
		int maxv = init(vp);
		int flag = 0;
		if (get<0>(vp.back()) != maxv - 1)
		{
			flag = 1;
			vp.emplace_back(maxv - 1, maxv, n);
		}
		int ans = 0;
		for (int i = 0; i < vp.size(); i++)
		{
			auto [l, r, pos] = vp[i];
			l = r - l;
			vp[i] = { r,-l,pos };
			sort(vp.begin(), vp.begin() + i + 1);
			int cur = l;
			dp[cur - 1] = 0;
			for (int j = 0; j <= i; j++)
			{
				auto [a, b, key] = vp[j];
				b = -b;
				swap(a, b);
				if (a < l || b > r) continue;
				while (cur <= b)
				{
					dp[cur] = dp[cur - 1];
					cur++;
				}
				if (a == l && b == r) break;
				dp[b] = max(dp[b], dp[a - 1] + res[key]);
			}
			res[pos] = dp[r] + 1;
			ans = max(ans, res[pos]);
		}
		ans -= flag;
		printf("%d\n", ans);
	}
	return 0;
}