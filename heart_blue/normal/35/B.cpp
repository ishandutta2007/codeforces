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
int flag[N][N];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	map<string, pair<int, int>> ms;
	int n, m, q;
	cin >> n >> m >> q;
	while (q--)
	{
		int op, x, y;
		string id;
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> id;
			for (int i = x; i <= n && !ms.count(id); i++)
			{
				for (int j = x == i ? y : 1; j <= m; j++)
				{
					if (flag[i][j] == 0)
					{
						ms[id] = { i,j };
						flag[i][j] = 1;
						break;
					}
				}
			}
		}
		else
		{
			cin >> id;
			int x = -1, y = -1;
			if (ms.count(id))
			{
				tie(x, y) = ms[id];
				ms.erase(id);
				flag[x][y] = 0;
			}
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}