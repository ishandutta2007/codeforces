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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
;
int ans = 0;
const int N = 3010;
char c[N][N];
int flag[N][N];
int cnt[N][N];
int cur = 0;
int pre = 0;
int n, m;
int dxy[4][2] = { 0, 1, 0, -1, -1, 0, 1, 0 };
string str = "DIMA";
int inf = 0;
int dfs(int x, int y, int px, int py, int num)
{
	if (x < 0 || x >= n) return 0;
	if (y < 0 || y >= m) return 0;
	if (c[x][y] != str[num]) return 0;
	if (num == 0 && px >= 0 && py >= 0 && flag[x][y] == -1)
	{
		if (cnt[x][y] > pre)
		{
			inf = 1;
			return 0;
		}
	}
	if (flag[x][y] >= 0) return flag[x][y];
	cnt[x][y] = ++cur;
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int t = dfs(x + dxy[i][0], y + dxy[i][1], x, y, (num + 1) % 4);
		ret = MAX(ret, t);
		if (inf) return 0;
	}
	if (num == 3) ret++;
	ans = MAX(ret, ans);
	return flag[x][y] = ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	MEM(flag, -1);
	MEM(cnt, 0);
	inf = 0;
	cur = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (c[i][j] == 'D' && flag[i][j] < 0)
			{
				dfs(i, j, -1, -1, 0);
				pre = cur;
				if (inf) break;
			}
		}
		if (inf) break;
	}
	if (inf)
	{
		cout << "Poor Inna!" << endl;
	}
	else if (ans == 0)
	{
		cout << "Poor Dima!" << endl;
	}
	else
	{
		cout << ans << endl;
	}
	return 0;
}


/*
int n, m, x, y, a, b;
cin >> n >> m >> x >> y >> a >> b;
int cnt1, cnt2;
int ans = 1 << 30;
cnt1 = ans;
if ((x - 1) % a == 0 && (y - 1) % b == 0)
{
if ((x - 1) / a == (y - 1) / b)
{
cnt1 = MIN(cnt1, (x - 1) / a);
}
}
if ((x - 1) % a == 0 && (m - y) % b == 0)
{
if ((x - 1) / a == (m - y) / b)
{
cnt1 = MIN(cnt1, (x - 1) / b);
}
}
if ((n - x) % a == 0 && (y - 1) % b == 0)
{
if ((n - x) / a == (y - 1) / b)
{
cnt1 = MIN(cnt1, (n - x) / a);
}
}
if ((n - x) % a == 0 && (m - y) % b == 0)
{
if ((n - x) / a == (m - y) / b)
{
cnt1 = MIN(cnt1, (n - x) / a);
}
}
if (cnt1 == ans)
{
cout << "Poor Inna and pony!" << endl;
}
else
{
cout << cnt1 << endl;
}
*/