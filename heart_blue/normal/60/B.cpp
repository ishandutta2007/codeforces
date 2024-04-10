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
const int N = 2e2 + 10;
char board[N][N][N];
int flag[N][N][N];
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 1,-1,0,0,0,0 };
int k, n, m;
int ans = 0;
void dfs(int x, int y, int z)
{
	if (x < 0 || x == k) return;
	if (y < 0 || y == n) return;
	if (z < 0 || z == m) return;
	if (flag[x][y][z]) return;
	if (board[x][y][z] == '#') return;
	flag[x][y][z] = 1;
	ans++;
	for (int i = 0; i < 6; i++)
	{
		dfs(x + dx[i], y + dy[i], z + dz[i]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> k >> n >> m;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	dfs(0, x - 1, y - 1);
	cout << ans << endl;
	return 0;
}