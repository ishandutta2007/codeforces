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
const int N = 1e6 + 10;
char datastr[N];
char* str[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", datastr + i * m);
		str[i] = datastr + i * m;
	}
	int cur = INF;
	for (int i = 0; i + 1 < n; i++)
	{
		for (int j = 0; j + 1 < m; j++)
		{
			if (str[i + 1][j] == 'X' && str[i][j + 1] == 'X')
			{
				ans[j + 1] = 1;
			}
		}
	}
	for (int i = 1; i <= m; i++)
		ans[i] += ans[i - 1];
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r || ans[l - 1] == ans[r - 1]) puts("YES");
		else puts("NO");
	}
	return 0;
}