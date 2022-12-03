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
int ans1[10][10], ans2[10][10];
char str[N];
int sum[N];
vector<int> v[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + str[i] - '0';
		}
		for (int i = 0; i < 10; i++) v[i].clear();
		int w, q;
		scanf("%d%d", &w, &q);
		MEM(ans1, -1);
		MEM(ans2, -1);
		for (int i = w; i <= n; i++)
		{
			v[(sum[i] - sum[i - w]) % 9].push_back(i - w + 1);
		}
		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				int inf = 1e9;
				pair<int, int> res = { inf,inf };
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if ((i * x + j) % 9 != y) continue;
						if (v[i].empty()) continue;
						if (v[j].empty()) continue;
						if (i != j)
						{
							res = min(res, { v[i][0],v[j][0] });
						}
						else if (v[i].size() > 1)
						{
							res = min(res, { v[i][0],v[i][1] });
						}
					}
				}
				if (res.first != inf)
					ans1[x][y] = res.first, ans2[x][y] = res.second;
			}
		}
		while (q--)
		{
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			int t = (sum[r] - sum[l - 1]) % 9;
			printf("%d %d\n", ans1[t][k], ans2[t][k]);
		}
	}
	return 0;
}