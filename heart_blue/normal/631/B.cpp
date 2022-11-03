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
const int N = 5e3 + 10;
int row[N], nrow[N];
int col[N], ncol[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(row, 0);
	MEM(nrow, 0);
	MEM(col, 0);
	MEM(ncol, 0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
	{
		int type, x, c;
		cin >> type >> x >> c;
		if (type == 1)
		{
			row[x] = c;
			nrow[x] = i;
		}
		else
		{
			col[x] = c;
			ncol[x] = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (nrow[i] > ncol[j]) cout << row[i];
			else cout << col[j];
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}