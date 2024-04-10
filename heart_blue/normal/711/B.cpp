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
const int N = 5e2 + 10;
LL a[N][N];
LL row[N];
LL col[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(row, 0);
	MEM(col, 0);
	int n;
	cin >> n;
	int x, y;
	x = y = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				x = i;
				y = j;
			}
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	LL o = row[(x + 1) % n] - row[x];
	row[x] += o;
	col[y] += o;
	int flag = 0;
	a[x][y] = o;
	for (int i = 0; i < n; i++)
	{
		if (row[i] != row[x]) flag = 1;
		if (col[i] != row[x]) flag = 1;
		if (flag) break;
	}
	LL sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) sum1 += a[i][i], sum2 += a[i][n - i - 1];
	if (sum1 != row[x] || sum2 != row[x]) flag = 1;
	if (flag || o <= 0) cout << -1 << endl;
	else cout << o << endl;
	return 0;
}