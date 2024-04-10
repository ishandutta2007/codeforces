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
const int N = 1e2 + 10;
int a[N][N];
int deg[N];
bool check(int n)
{
	MEM(deg, 0);
	int tot = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == 1) deg[j]++;
		}
	}
	for (int i = 1; i <= n; i++) if (deg[i] == 0) q.push(i);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		tot++;
		for (int i = 1; i <= n; i++)
		{
			if (a[x][i])
			{
				deg[i]--;
				if (deg[i] == 0) q.push(i);
			}
		}
	}
	return tot == n;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int tot = n*(n - 1) / 2 - 1;
	MEM(a, 0);
	while (tot--)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i][j] == 0 && a[j][i] == 0)
			{
				a[i][j] = 1;
				if (check(n))
				{
					cout << i << ' ' << j << endl;
				}
				else
					cout << j << ' ' << i << endl;
			}
		}
	}
	return 0;
}