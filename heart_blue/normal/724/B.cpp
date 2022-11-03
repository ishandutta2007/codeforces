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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N][N];
int n, m;
void refrain(int x, int y)
{
	for (int i = 1; i <= n; i++) swap(a[i][x], a[i][y]);
}
bool check(int x, int y)
{
	refrain(x, y);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] != j) cnt++;
		}
		if (cnt != 0 && cnt != 2) break;
	}
	refrain(x, y);
	return cnt == 0 || cnt == 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			if (check(i, j))
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");

	return 0;
}