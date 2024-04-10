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
const LL INF = 1e9 + 1;
const int N = 2e2;
int a[N][N];
char c[N][N];
vector<pair<int, int>> vp1,vp2;
int flag[N][N];
int flag1[N][N];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == 'o') vp1.push_back({ i, j });
			if (c[i][j] == 'x') cnt++;
		}
	}
	int bx = n - 1, by = n - 1;
	MEM(flag, 0);
	for (int s = 0; s < vp1.size(); s++)
	{
		int tx, ty;
		tie(tx, ty) = vp1[s];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == tx && j == ty) continue;
				if (c[i][j] == 'o') continue;
				int dx = i - tx;
				int dy = j - ty;
				int &f = flag[bx + dx][by + dy];
				if (!f)
				{
					if (c[i][j] == 'x') f = 2;
					else f = 1;
				}
				else
				{
					if (c[i][j] == 'x' && f != 2) f = -1;
					if (c[i][j] != 'x' && f != 1) f = -1;
				}
			}
		}
	}
	MEM(flag1, 0);
	for (int s = 0; s < vp1.size(); s++)
	{
		int tx, ty;
		tie(tx, ty) = vp1[s];
		for (int i = -n + 1; i < n; i++)
		{
			if (tx + i < 0) continue;
			if (tx + i > n) continue;
			for (int j = -n + 1; j < n; j++)
			{
				if (ty + j < 0) continue;
				if (ty + j > n) continue;
				if (flag[bx + i][by + j] != 2) continue;
				if (c[tx + i][ty + j] == 'x')
				{
					if (!flag1[tx + i][ty + j]) flag1[tx + i][ty + j] = 1, cnt--;
				}
			}
		}
	}
	if (cnt)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		for (int i = 0; i < 2 * n - 1; i++)
		{
			for (int j = 0; j < 2 * n - 1; j++)
			{
				if (i == n - 1 && j == n - 1)
				{
					cout << 'o';
					continue;
				}
				if (flag[i][j] == 2) cout << 'x';
				else cout << '.';
			}
			cout << endl;
		}
	}
	return 0;
}