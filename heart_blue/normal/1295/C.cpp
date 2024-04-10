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
const int N = 2e5 + 10;
char s1[N], s2[N];
int nex[N][130];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s%s", s1 + 1, s2 + 1);
		int n = strlen(s1 + 1);
		int m = strlen(s2 + 1);
		for (int i = 0; i <= n + 1; i++) MEM(nex[i], 0);
		for (int i = n; i >= 1; i--)
		{
			memcpy(nex[i], nex[i + 1], sizeof(nex[i]));
			nex[i][s1[i]] = i;
		}
		for (int i = n + 1; i >= 1; i--)
		{
			for (int o = 'a'; o <= 'z'; o++)
			{
				if (nex[i][o] == 0)
					nex[i][o] = nex[1][o];
			}
		}
		int cur = 1;
		int ans = 1;
		for (int i = 1; i <= m; i++)
		{
			int x = nex[cur][s2[i]];
			if (x == 0)
			{
				ans = -1;
				break;
			}
			if (x < cur) ans++;
			cur = x + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}