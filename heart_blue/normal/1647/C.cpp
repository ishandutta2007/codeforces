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
char str[200][200];
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
		vector<tuple<int, int, int, int>> vp;
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
		}
		for (int i = n; i >= 1; i--)
		{
			for (int j = m; j >= 1; j--)
			{
				if (str[i][j] == '0')
					vp.emplace_back(i, j, i, j);
				else if (i > 1)
					vp.emplace_back(i - 1, j, i, j);
				else if (j > 1)
					vp.emplace_back(i, j - 1, i, j);
				else
					flag = 0;
			}
		}
		if (flag == 0) puts("-1");
		else
		{
			printf("%d\n", vp.size());
			for (auto& [a, b, c, d] : vp)
				printf("%d %d %d %d\n", a, b, c, d);
		}
	}
	return 0;
}