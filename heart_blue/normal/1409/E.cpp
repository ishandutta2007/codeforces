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
pair<int, int> vp[N];
int maxv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		map<int, int> mc;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
		}
		for (int i = 0; i < n; i++) scanf("%*d");
		int sz = 0;
		for (auto& p : mc)
		{
			vp[++sz] = p;
		}
		for (int i = 1; i <= sz; i++)
		{
			vp[i].second += vp[i - 1].second;
		}
		maxv[sz + 1] = 0;
		for (int i = sz; i >= 1; i--)
		{
			int pos = upper_bound(vp + 1, vp + sz + 1, make_pair(vp[i].first + k, int(INF))) - vp - 1;
			maxv[i] = max(maxv[i + 1], vp[pos].second - vp[i - 1].second);
		}
		int ans = 0;
		for (int i = 1; i <= sz; i++)
		{
			int pos = upper_bound(vp + 1, vp + sz + 1, make_pair(vp[i].first + k, int(INF))) - vp - 1;
			ans = max(ans, vp[pos].second - vp[i - 1].second + maxv[pos + 1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}