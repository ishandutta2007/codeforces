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
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ans = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		ans += x;
	}
	int q;
	scanf("%d", &q);
	map<pair<int, int>, int> mc;
	while (q--)
	{
		int s, t, u;
		scanf("%d%d%d", &s, &t, &u);
		if (mc.count({ s,t }))
		{
			int v = mc[{s, t}];
			deg[v]--;
			if (deg[v] < a[v]) ans++;
			mc.erase(make_pair(s, t));
		}
		if (u != 0)
		{
			deg[u]++;
			if (deg[u] <= a[u])
				ans--;
			mc[{s, t}] = u;
		}
		printf("%lld\n", ans);
	}
	return 0;
}