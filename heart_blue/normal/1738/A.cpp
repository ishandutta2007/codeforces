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
int a[N];
LL solve(vector<int> v1, vector<int> v2)
{
	LL ans = 0;
	for (auto& x : v1) ans += x;
	for (auto& x : v2) ans += x;
	int cnt[2] = { int(v1.size()),int(v2.size()) };
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	vector<int> v[2] = { v1,v2 };
	int cur = 0;
	int o = 0;
	while (cnt[o])
	{
		cnt[o]--;
		if (cur++)
		{
			ans += v[o].back();
			v[o].pop_back();
		}
		o ^= 1;
	}
	return ans;
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (a[i] & 1) v1.push_back(x);
			else v2.push_back(x);
		}
		printf("%lld\n", max(solve(v1, v2), solve(v2, v1)));
	}
	return 0;
}