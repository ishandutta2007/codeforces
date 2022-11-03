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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		LL sum1 = 0, sum2 = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++)
		{
			int b;
			scanf("%d", &b);
			if (b == 1) sum1 += a[i], v1.push_back(a[i]);
			else sum2 += a[i], v2.push_back(a[i]);
		}
		if (sum1 + sum2 < m)
		{
			puts("-1");
			continue;
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int cnt1 = v1.size();
		int cnt2 = v2.size();
		int ans = INF;
		LL cur1 = 0;
		LL cur2 = 0;
		for (int i = 0; i <= v1.size(); i++)
		{
			while (!v2.empty() && sum1 - cur1 + cur2 < m)
			{
				cur2 += v2.back();
				v2.pop_back();
			}
			if (sum1 - cur1 + cur2 >= m)
			{
				ans = min(ans, int((cnt2 - v2.size()) * 2 + v1.size() - i));
			}
			if (i == v1.size()) break;
			cur1 += v1[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}