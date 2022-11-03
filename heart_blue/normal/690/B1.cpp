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
const int N = 3e2 + 10;
char str[N][N];
int cnt[N];
bool check(int lx, int rx, int ly, int ry)
{
	int tot = (rx - lx + 1) * (ry - ly + 1);
	int cnt4 = (rx - lx - 1) * (ry - ly - 1);
	if (cnt['1'] != 4) return false;
	if (cnt['3'] > 0) return false;
	if (cnt['4'] != cnt4) return false;
	if (cnt['2'] != tot - cnt4 - 4) return false;
	if (str[lx][ly] != '1' || str[lx][ry] != '1' || str[rx][ly] != '1' || str[rx][ry] != '1')
		return false;
	for (int i = lx + 1; i < rx; i++)
	{
		for (int j = ly + 1; j < ry; j++)
		{
			if (str[i][j] != '4') return false;
		}
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int lx = INF, rx = 0, ly = INF, ry = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= n; j++)
		{
			cnt[str[i][j]]++;
			if (str[i][j] != '0')
			{
				lx = min(lx, i);
				rx = max(rx, i);
				ly = min(ly, j);
				ry = max(ry, j);
			}
		}
	}
	if (cnt['4'] == 0) puts("No");
	else if (check(lx, rx, ly, ry)) puts("Yes");
	else puts("No");
	return 0;
}