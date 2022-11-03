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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
char str[N][N];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int check(int x, int y, int o)
{
	int tot = 0;
	while (str[x][y] == '*')
	{
		tot++;
		x += dx[o];
		y += dy[o];
	}
	return tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> (str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			tot += str[i][j] == '*';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] != '*') continue;
			int flag = 1;
			int sum = 0;
			for (int k = 0; k < 4; k++)
			{
				int res = check(i, j, k);
				if (res <= 1) flag = 0;
				sum += res;
			}
			sum -= 3;
			if (sum != tot) flag = 0;
			if (flag) puts("YES"), exit(0);
		}
	}
	puts("NO");
	
	return 0;
}