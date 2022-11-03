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
const int N = 3e2 + 10;
int a[N][N];
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
		int ok = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int cnt = 4;
				if (i == 1) cnt--;
				if (i == n) cnt--;
				if (j == 1) cnt--;
				if (j == m) cnt--;
				int x;
				scanf("%d", &x);
				if (x > cnt) ok = 0;
				a[i][j] = cnt;
			}
		}
		if (!ok) puts("NO");
		else
		{
			puts("YES");
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					printf("%d%c", a[i][j], " \n"[j == m]);
				}
			}
		}
	}
	return 0;
}