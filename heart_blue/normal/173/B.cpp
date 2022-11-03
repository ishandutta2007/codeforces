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
const int N = 1e3 + 10;
char str[N][N];
int row[N];
int col[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	queue<pair<int, int>> q;
	row[n] = 1;
	q.emplace(n, 0);
	while (!q.empty())
	{
		int x, o;
		tie(x, o) = q.front();
		q.pop();
		if (o == 0)
		{
			for (int i = 1; i <= m; i++)
			{
				if (str[x][i] != '#') continue;
				if (col[i]) continue;
				q.emplace(i, 1);
				col[i] = row[x] + 1;
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (str[i][x] != '#') continue;
				if (row[i]) continue;
				q.emplace(i, 0);
				row[i] = col[x] + 1;
			}
		}
	}
	printf("%d\n", row[1] - 1);
	return 0;
}