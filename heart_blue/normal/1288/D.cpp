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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int pos[300];
int a[N][8];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int tot = 1 << m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int l = 0, r = INF;
	tuple<int, int, int> ans{ 0,0,0 };
	while (l <= r)
	{
		int mid = (l + r) / 2;
		MEM(pos, -1);
		for (int i = 1; i <= n; i++)
		{
			int o = 0;
			for (int j = 0; j < m; j++)
			{
				o |= (a[i][j] >= mid) << j;
			}
			pos[o] = i;
		}
		tuple<int, int, int> key = { -1,-1,-1 };
		int flag = 0;
		for (int i = 0; i < tot; i++)
		{
			for (int j = i; j < tot; j++)
			{
				if ((i | j) != tot - 1) continue;
				if (pos[i] > 0 && pos[j] > 0)
				{
					key = { mid,pos[i],pos[j] };
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}

		if (flag) ans = key, l = mid + 1;
		else r = mid - 1;
	}
	int z, x, y;
	tie(z, x, y) = ans;
	//cout << z << endl;
	printf("%d %d\n", x, y);
	return 0;
}