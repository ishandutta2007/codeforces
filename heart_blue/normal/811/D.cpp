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
const int N = 1e2 + 10;
char str[N][N];
pair<int, int> pre[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
string key = "LRUD";
int flag[4];
int vis[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i] + 1;
	}
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	vis[1][1] = 1;
	int kx = -1, ky = -1;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (str[x][y] == 'F')
		{
			kx = x, ky = y;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 1 || tx > n) continue;
			if (ty < 1 || ty > m) continue;
			if (str[tx][ty] == '*') continue;
			if (vis[tx][ty]) continue;
			vis[tx][ty] = 1;
			q.emplace(tx, ty);
			pre[tx][ty] = { x,y };
		} 
	}
	vector<pair<int, int>> vp;
	while (kx != 1 || ky != 1)
	{
		vp.emplace_back(kx, ky);
		tie(kx, ky) = pre[kx][ky];
	}
	int x = 1, y = 1;
	while (!vp.empty())
	{
		int o = 0;
		auto [tx, ty] = vp.back();
		vp.pop_back();
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] == tx && y + dy[i] == ty)
			{
				o = i;
				break;
			}
		}
		if (flag[o] == 0)
		{
			flag[o] = flag[o ^ 1] = 1;
			cout << key[o] << endl;
			int x0, y0;
			cin >> x0 >> y0;
			if (x0 == x && y0 == y)
			{
				swap(key[o], key[o ^ 1]);
				cout << key[o] << endl;
				cin >> x >> y;
			}
			else
				x = x0, y = y0;
			continue;
		}
		cout << key[o] << endl;
		cin >> x >> y;
	}
	return 0;

}