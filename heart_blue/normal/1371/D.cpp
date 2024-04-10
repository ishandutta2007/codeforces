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
const int N = 4e2 + 10;
char ans[N][N];
int row[N], col[N];
int solve(int a[], int n)
{
	int minv = INF;
	int maxv = 0;
	for (int i = 0; i < n; i++)
	{
		minv = min(minv, a[i]);
		maxv = max(maxv, a[i]);
	}
	return (maxv - minv) * (maxv - minv);
}
int main()
{
	//freopen("input.txt", "r", stdin);1
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		MEM(ans, '0');
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) ans[i][n] = 0;
		int x = 0, y = 0;
		MEM(row, 0);
		MEM(col, 0);
		while (k--)
		{
			ans[x][y] = '1';
			row[x]++;
			col[y]++;
			x++, y++;
			if (x >= n) x = 0;
			if (y >= n) y = 0;
			if (ans[x][y] == '1') y++;
			if (y >= n) y = 0;
		}
		printf("%d\n", solve(row, n) + solve(col, n));
		for (int i = 0; i < n; i++) puts(ans[i]);
	}
	return 0;
}