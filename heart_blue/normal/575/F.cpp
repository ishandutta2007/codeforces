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
const int N = 1e4 + 10;
int a[N];
pair<int, int> p[N];
LL dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	scanf("%d%d", &n, &x);
	vector<int> v;
	v.push_back(x);
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		p[i] = { l,r };
		v.push_back(l);
		v.push_back(r);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 1; i <= v.size(); i++)
	{
		a[i] = v[i - 1];
	}
	p[0] = { x,x };
	int sz = v.size();
	for (int i = 0; i <= n; i++)
	{
		auto [l, r] = p[i];
		for (int j = 1; j <= sz; j++)
		{
			if (a[j] <= l) dp[j] += l - a[j];
			if (a[j] >= r) dp[j] += a[j] - r;
		}
		for (int j = 2; j <= sz; j++)
		{
			dp[j] = min(dp[j], dp[j - 1] + a[j] - a[j - 1]);
		}
		for (int j = sz - 1; j >= 1; j--)
		{
			dp[j] = min(dp[j], dp[j + 1] + a[j + 1] - a[j]);
		}
	}
	LL ans = *min_element(dp + 1, dp + sz + 1);
	printf("%lld\n", ans);
	return 0;
}