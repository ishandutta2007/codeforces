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
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char c[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == '.') c[i][j] = 'D';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == 'S')
			{
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (c[x][y] == 'W')
					{
						puts("No");
						return 0;
					}
				}
			}
		}
	}
	puts("Yes");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			putchar(c[i][j]);
		}
		puts("");
	}
	return 0;
}