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
const int N = 5e2 + 10;
int a[N][N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int key = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
		if (count(a[i] + 1, a[i] + m + 1, a[i][1]) != m) key = i;
		sum ^= a[i][1];
	}
	fill(ans + 1, ans + n + 1, 1);
	if (sum)
	{
		puts("TAK");
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
		return 0;
	}
	if (key == 0) puts("NIE"), exit(0);
	for (int i = 1; i <= m; i++)
	{
		if (a[key][1] != a[key][i])
		{
			ans[key] = i;
		}
	}
	puts("TAK");
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}