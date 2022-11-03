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
const int N = 3e2 + 10;
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(str, ' ');
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			int o = 0;
			for (int i = n; i >= 1; i--)
			{
				if (str[i][j] == 'o') o = 0;
				else if (str[i][j] == '.') o++;
				else swap(str[i][j], str[i + o][j]);
			}
		}
		for (int i = 1; i <= n; i++)
			puts(str[i] + 1);
	}
	return 0;

}