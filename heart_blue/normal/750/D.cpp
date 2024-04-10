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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { 1,1,0,-1,-1,-1,0,1 };
int flag[N][N][31][8];
int cnt[N][N];
int a[N];
int n;
void dfs(int x, int y, int cur, int o)
{
	if (cur > n) return;
	if (o < 0) o += 8;
	if (o == 8) o = 0;
	if (flag[x][y][cur][o]) return;
	flag[x][y][cur][o] = 1;
	for (int i = 1; i <= a[cur]; i++)
	{
		cnt[x + dx[o] * i][y + dy[o] * i] = 1;
	}
	dfs(x + dx[o] * a[cur], y + dy[o] * a[cur], cur + 1, o + 1);
	dfs(x + dx[o] * a[cur], y + dy[o] * a[cur], cur + 1, o - 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	MEM(flag, 0);
	MEM(cnt, 0);
	int ans = 0;
	dfs(300, 300, 1, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans += cnt[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}