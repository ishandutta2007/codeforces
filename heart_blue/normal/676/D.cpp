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
const double eps = 1e-10;
const LL N = 1e3 + 20;
vector<int> v[128];
vector<char> rot[128];
char chess[N][N];
int dp[N][N][4];
int vis[N][N][4];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void init()
{
	v['+'] = { 0,0,0,0 };
	v['-'] = { 1,1,0,0 };
	v['|'] = { 0,0,1,1 };
	v['^'] = { 0,2,3,1 };
	v['>'] = { 3,1,2,0 };
	v['<'] = { 1,3,0,2 };
	v['v'] = { 2,0,1,3 };
	v['L'] = { 0,0,1,0 };
	v['R'] = { 0,0,0,1 };
	v['U'] = { 1,0,0,0 };
	v['D'] = { 0,1,0,0 };
	rot['+'] = { '+','+','+','+' };
	rot['-'] = { '-','|','-','|' };
	rot['|'] = { '|','-','|' ,'-' };
	rot['^'] = { '^','>','v','<' };
	rot['>'] = { '>','v','<','^' };
	rot['<'] = { '<','^','>','v' };
	rot['v'] = { 'v','<','^','>' };
	rot['L'] = { 'L','U','R','D' };
	rot['R'] = { 'R','D','L','U' };
	rot['U'] = { 'U','R','D','L' };
	rot['D'] = { 'D','L','U','R' };

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	init();
	cin >> n >> m;
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> chess[i][j];
			for (int k = 0; k < 4; k++) dp[i][j][k] = INF;
		}
	}

	int x, y;
	int s, t;
	cin >> x >> y;
	cin >> s >> t;

	if (x == s && y == t)
	{
		cout << 0 << endl;
		return 0;
	}
	typedef pair<int, tuple<int, int, int>> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (int i = 0; i < 4; i++)
	{
		dp[x][y][i] = i;
		pq.push({ i,{x,y,i} });
	}
	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();
		int x, y, o;
		tie(x, y, o) = p.second;
		int d = p.first;
		if (vis[x][y][o]) continue;
		vis[x][y][o] = 1;
		if (chess[x][y] == '*') continue;
		char cur = rot[chess[x][y]][o];
		for (int i = 0; i < 4; i++)
		{
			if (v[cur][i] != 0) continue;
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx <= 0 || tx > n) continue;
			if (ty <= 0 || ty > m) continue;
			if (chess[tx][ty] == '*') continue;
			char dir = rot[chess[tx][ty]][o];
			if (v[dir][i ^ 1] != 0) continue;
			for (int j = 0; j < 4; j++)
			{
				int tmp = dp[x][y][o] + 1 + j;
				if (ans <= tmp)
				{
					continue;
				}
				if (dp[tx][ty][(j + o) % 4] > tmp)
				{
					pq.push({ tmp,{tx,ty,(j + o) % 4} });
					dp[tx][ty][(j + o) % 4] = tmp;
				}
				if (tx == s && ty == t)
				{
					ans = min(ans, tmp);
				}
			}
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}