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
#include <iterator>
#include <complex>
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, r, c;
		scanf("%d%d%d%d", &n, &m, &r, &c);
		int cnt = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
			for (int j = 1; j <= m; j++)
			{
				if (str[i][j] == 'B')
				{
					cnt++;
					if (i == r) cnt1++;
					if (j == c) cnt2++;
				}
			}
		}
		if (str[r][c] == 'B') puts("0");
		else if (cnt1 || cnt2) puts("1");
		else if (cnt) puts("2");
		else puts("-1");

	}
	return 0;
}