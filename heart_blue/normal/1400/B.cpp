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
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int p, f;
		int cnt1, cnt2;
		int s, w;
		scanf("%d%d", &p, &f);
		scanf("%d%d", &cnt1, &cnt2);
		scanf("%d%d", &s, &w);
		if (s > w) swap(s, w), swap(cnt1, cnt2);
		int ans = 0;
		for (int i = 0; i <= cnt1 && i * s <= p; i++)
		{
			int cost1 = i, cost2 = min(cnt2, (p - s * i) / w);
			int rest1 = cnt1 - i, rest2 = cnt2 - cost2;
			int tot = f;
			int o1 = min(rest1, tot / s);
			tot -= o1 * s;
			int o2 = min(rest2, tot / w);
			ans = max(ans, cost1 + cost2 + o1 + o2);
		}
		printf("%d\n", ans);

	}
	return 0;
}