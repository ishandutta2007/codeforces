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
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		fill(flag + 1, flag + 3 * n + 1, 0);
		vector<int> ans2;
		vector<int> ans1;
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (flag[x] || flag[y]) continue;
			ans2.push_back(i);
			flag[x] = flag[y] = 1;
		}
		for (int i = 1; i <= 3 * n; i++)
		{
			if (flag[i] == 0)
				ans1.push_back(i);
		}
		if (ans1.size() >= n)
		{
			puts("IndSet");
			for (int i = 0; i < n; i++)
			{
				printf("%d%c", ans1[i], " \n"[i + 1 == n]);
			}
		}
		else
		{
			puts("Matching");
			for (int i = 0; i < n; i++)
			{
				printf("%d%c", ans2[i], " \n"[i + 1 == n]);
			}
		}
	}
	return 0;
}