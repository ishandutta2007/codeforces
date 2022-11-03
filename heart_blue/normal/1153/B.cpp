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
const int N = 2e2 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, h;
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		for (int j = 1; j <= n; j++)
		{
			a[j][i] = x;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = min(a[i][j], x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			printf("%d%c", a[i][j] * x, " \n"[j == m]);
		}
	}
	return 0;
}