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
vector<int> v[2];
int a[N];
LL check(vector<int>& v1, vector<int>& v2, int o1, int o2)
{
	LL ret = 0;
	int cnt1 = v1.size();
	int cnt2 = v2.size();
	int n = cnt1 + cnt2;
	for (int i = 1; i <= n; i++)
	{
		if (i & 1)
		{
			if (cnt1 > 0) cnt1--, a[i] = o1;
			else cnt2--, a[i] = o2;
		}
		else
		{
			if (cnt2 > 0) cnt2--, a[i] = o2;
			else cnt1--, a[i] = o1;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i + 1]) return INF * INF;
	}
	int ptr = 0;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == o1)
		{
			ans += abs(v1[ptr++] - i);
		}
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
		v[0].clear();
		v[1].clear();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			x &= 1;
			v[x].push_back(i);
		}
		LL ans = min(check(v[0], v[1], 0, 1), check(v[1], v[0], 1, 0));
		if (ans == INF * INF) ans = -1;
		printf("%lld\n", ans);
	}
	return 0;
}