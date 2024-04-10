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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
char s[3][3];
char ans[N][N];
int n, k;
void dfs(int ox, int oy, int len, char c = '.')
{
	if (c == '*')
	{
		for (int i = 0; i < len * n; i++)
		{
			for (int j = 0; j < len * n; j++)
			{
				ans[ox + i][oy + j] = '*';
			}
		}
		return;
	}
	if (len == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans[ox + i][oy + j] = s[i][j];
			}
		}
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dfs(ox + i * len, oy + j * len, len / n, s[i][j]);
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int p2[] = { 1,2,4,8,16,32 };
	int p3[] = { 1,3,9,27,81,243 };
	cin >> n >> k;
	int sz;
	if (n == 2) sz = p2[k];
	else sz = p3[k];
	for (int i = 0; i < n; i++) cin >> s[i];
	dfs(0, 0, sz / n);
	for (int i = 0; i < sz; i++)
		cout << ans[i] << endl;
	return 0;
}