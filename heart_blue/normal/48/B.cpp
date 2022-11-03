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

int a[N][N];
int getsum(int a1, int b1, int a2, int b2)
{
	return a[a2][b2] - a[a1 - 1][b2] - a[a2][b1 - 1] + a[a1 - 1][b1 - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
		}
	}
	int a, b;
	cin >> a >> b;
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i >= a && j >= b)
			{
				ans = min(ans, getsum(i - a + 1, j - b + 1, i, j));
			}
			if (i >= b && j >= a)
			{
				ans = min(ans, getsum(i - b + 1, j - a + 1, i, j));
			}
		}
	}
	cout << ans << endl;
	return 0;
}