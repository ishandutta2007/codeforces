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
vector<int> v[N];
int ans[N];
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
		for (int i = 1; i <= n; i++) v[i].clear();
		memset(ans, 0, sizeof(int) * (n + 1));
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (v[x].size() < k)
				v[x].push_back(i), tot++;
		}
		tot = tot / k * k;
		int cur = 0;
		for (int i = 1; i <= n; i++)
		{
			for (auto& x : v[i])
			{
				if (cur >= tot) break;
				ans[x] = cur % k + 1;
				cur++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", ans[i], " \n"[i == n]);
		}
	}
	return 0;
}