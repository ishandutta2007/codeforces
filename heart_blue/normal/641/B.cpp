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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N][N];
int pr[N];
int pc[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(pr, 0);
	MEM(pc, 0);
	MEM(a, 0);
	int n, m, q;
	cin >> n >> m >> q;
	function<void(int)> dfs = [&] (int cur)
	{
		int op, x, y, w;
		if (cur == 0) return;
		cin >> op;
		if (op == 1)
		{
			cin >> x;
			dfs(cur - 1);
			x--;
			for (int i = m; i > 0; i--) a[x][i] = a[x][i - 1];
			a[x][0] = a[x][m];
		}
		if (op == 2)
		{
			cin >> y;
			dfs(cur - 1);
			y--;
			for (int i = n; i > 0; i--) a[i][y] = a[i - 1][y];
			a[0][y] = a[n][y];
		}
		if (op == 3)
		{
			cin >> x >> y >> w;
			dfs(cur - 1);
			x--, y--;
			a[x][y] = w;
		}
	};
	dfs(q);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}