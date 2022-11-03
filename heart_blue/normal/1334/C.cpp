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
pair<LL, LL> a[N];
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
		LL tota = 0;
		LL totb = 0;
		for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i].first, &a[i].second);
		a[0] = a[n];
		for (int i = 0; i < n; i++)
		{
			a[i].second = min(a[i].second, a[i + 1].first);
			tota += a[i].first;
			totb += a[i].second;
		}
		LL ans = INF * INF;
		for (int i = 1; i <= n; i++)
		{
			ans = min(ans, tota - totb + a[i - 1].second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}