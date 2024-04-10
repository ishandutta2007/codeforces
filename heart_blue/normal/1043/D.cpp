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
int pos[N][20];
int a[20][N];
LL sum(LL x)
{
	return x * (x + 1) / 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int o = 1; o <= m; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[o][i]);
			pos[a[o][i]][o] = i;
		}
		pos[n + 1][o] = -o;
	}
	LL ans = 0;
	int *b = a[1];
	for (int i = 1; i <= n; i++)
	{
		int p[11];
		for (int o = 1; o <= m; o++)
		{
			p[o] = pos[b[i]][o];
		}
		int o = i;
		while (1)
		{
			o++;
			for (int j = 1; j <= m; j++) p[j]++;
			int flag = 0;
			for (int j = 1; j <= m; j++)
			{
				if (p[j] > n)
				{
					flag = 1;
					break;
				}
			}
			if (flag) break;
			for (int j = 2; j <= m; j++)
			{
				if (a[j][p[j]] != a[j - 1][p[j - 1]])
				{
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		ans += sum(o - i);
		if (o > n) break;
		i = o - 1;
	}
	cout << ans << '\n';
	return 0;
}