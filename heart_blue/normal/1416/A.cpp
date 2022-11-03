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
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) ans[i] = INF;
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		for (int i = 1; i <= n; i++)
		{
			if (v[i].empty()) continue;
			int res = max(v[i].front(), n - v[i].back() + 1);
			for (int j = 1; j < v[i].size(); j++)
			{
				res = max(res, v[i][j] - v[i][j - 1]);
			}
			ans[res] = min(ans[res], i);
		}
		for (int i = 2; i <= n; i++)
			ans[i] = min(ans[i], ans[i - 1]);
		for (int i = 1; i <= n; i++)
		{
			if (ans[i] == INF)
				ans[i] = -1;
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}