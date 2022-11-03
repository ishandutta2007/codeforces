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
const int N = 1e5 + 10;
int flag[N];
vector<int> v[N];

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
		for (int i = 0; i < n; i++)
		{
			v[i].clear();
			for (int j = 0; j < m; j++)
			{
				int x;
				scanf("%d", &x);
				v[i].push_back(x);
			}
		}
		int ans = 0;
		int l = 0, r = INF;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			fill(flag, flag + m, 0);
			int ok = 0;
			for (int i = 0; i < n; i++)
			{
				int cnt = 0;
				for (int j = 0; j < m; j++)
				{
					if (v[i][j] >= mid)
						flag[j] = 1, cnt++;
				}
				if (cnt >= 2)
				{
					ok = 1;
				}
			}
			if (count(flag, flag + m, 1) == m && ok)
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}