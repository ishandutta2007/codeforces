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
int a[20][N][N];
void init(int b[N][N])
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
		}
	}
}
int sum(int b[N][N], int ax, int ay, int bx, int by)
{
	return b[bx][by] - b[ax - 1][by] - b[bx][ay - 1] + b[ax - 1][ay - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	int n, q, c;
	cin >> n >> q >> c;
	for (int i = 0; i < n; i++)
	{
		int x, y, val;
		cin >> x >> y >> val;
		a[val][x][y]++;
	}
	for (int i = 0; i <= c; i++) init(a[i]);
	while (q--)
	{
		int t, ax, ay, bx, by;
		cin >> t >> ax >> ay >> bx >> by;
		LL ans = 0;
		for (int i = 0; i <= c; i++)
		{
			ans += sum(a[i], ax, ay, bx, by)*((i + t) % (c + 1));
		}
		printf("%lld\n", ans);
	}

	return 0;
}