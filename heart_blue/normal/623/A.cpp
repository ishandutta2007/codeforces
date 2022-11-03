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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
int a[N][N];
int sum[N];
string ans;
bool check(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int o = abs(ans[i] - ans[j]);
			if (o == 2) o = 0;
			else o = 1;
			if (a[i][j] != o) return false;
		}
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(a, 0);
	MEM(sum, 0);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		sum[x] ++;
		sum[y] ++;
		a[x][y] = a[y][x] = 1;
	}
	ans = string(n, 'a');
	int o = -1;
	for (int i = 0; i < n; i++)
	{
		if (sum[i] == n - 1) ans[i] = 'b';
		else o = i;
	}
	if (o != -1)
	{
		for (int i = 0; i < n; i++)
		{
			if (ans[i] == 'b') continue;
			if (i == o) continue;
			if (a[i][o] != 1) ans[i] = 'c';
		}
	}
	if (check(n))
	{
		puts("Yes");
		puts(ans.c_str());
	}
	else
	{
		puts("No");
	}
	return 0;
}