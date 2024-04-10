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
const int N = 3e2 + 10;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int sx, sy, ex, ey;
char board[N][N];
int a[4] = { 0,1,2,3 };
string str;
int n, m;
bool solve()
{
	map<char, int> mc;
	for (int i = 0; i < 4; i++) mc[i + '0'] = a[i];
	int x = sx, y = sy;
	for (auto &c : str)
	{
		int o = mc[c];
		x += dx[o];
		y += dy[o];
		if (x < 0 || x >= n) return false;
		if (y < 0 || y >= m) return false;
		if (board[x][y] == '#') return false;
		if (board[x][y] == 'E') return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	cin >> str;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'S')
			{
				sx = i, sy = j;
			}
			if (board[i][j] == 'E')
			{
				ex = i, ey = j;
			}
		}
	}
	do
	{
		if (solve()) ans++;
	} while (next_permutation(a, a + 4));
	cout << ans << endl;
	return 0;
}