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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e1 + 10;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int flag[N][N];
int fx[N];
int fy[N];
int n, m;
int cnt;
void dfs(int x, int y)
{
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	if (flag[x][y]) return;
	cnt++;
	flag[x][y] = 1;
	int o;
	o = fx[x];
	dfs(x + dx[o], y + dy[o]);
	o = fy[y];
	dfs(x + dx[o], y + dy[o]);

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == '<') fx[i] = 0;
		else fx[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		char c;
		cin >> c;
		if (c == '^') fy[i] = 2;
		else fy[i] = 3;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			MEM(flag, 0);
			cnt = 0;
			dfs(i, j);
			if (cnt != n*m)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}