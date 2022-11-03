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
const int N = 1e3 + 10;
int flag[N][N];
int n;
int dx[] = { 1,1,1,-1,-1,-1,0,0 };
int dy[] = { -1,0,1,-1,0,1,-1,1 };
void dfs(int x, int y)
{
	if (x < 1 || x > n) return;
	if (y < 1 || y > n) return;
	if (flag[x][y]) return;
	flag[x][y] = 1;
	for (int o = 0; o < 8; o++)
	{
		dfs(x + dx[o], y + dy[o]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ax, ay;
	int bx, by;
	int cx, cy;
	cin >> n;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == ax || j == ay)
			{
				flag[i][j] = 1;
			}
			if (i - j == ax - ay || i + j == ax + ay)
			{
				flag[i][j] = 1;
			}
		}
	}
	dfs(bx, by);
	if (flag[cx][cy]) puts("YES");
	else puts("NO");
	return 0;
}