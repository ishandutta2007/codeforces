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
const int N = 3e5 + 10;
int cnt[N];
LL check(vector<int>& v, int p)
{
	sort(v.begin(), v.end());
	auto v2 = v;
	LL ret = 0;
	int cost = 0;
	for (auto& x : v2)
	{
		while (!v2.empty() && x + v2.back() >= p) v2.pop_back(), cost++;
		ret += cost;
	}
	for (auto& x : v)
	{
		if (x * 2 >= p) ret--;
	}
	ret /= 2;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<pair<int, int>, int> mc;
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y) swap(x, y);
		mc[{x, y}]++;
		cnt[x]++;
		cnt[y]++;
	}
	LL ans = 0;
	int tot = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] >= p) tot++;
		else v.push_back(cnt[i]);
	}
	ans += 1LL * tot * (tot - 1) / 2 + 1LL*tot * (n - tot);
	ans += check(v, p);
	for (auto& pp : mc)
	{
		int x, y;
		tie(x, y) = pp.first;
		int c = pp.second;
		if (cnt[x] + cnt[y] >= p && cnt[x] + cnt[y] - c < p) 
			ans--;
	}
	printf("%lld\n", ans);
	return 0;
}