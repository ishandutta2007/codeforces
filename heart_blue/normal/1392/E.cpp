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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e1 + 10;
LL a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, -1);
	int n;
	cin >> n;
	a[1][1] = a[n][n] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i + j != 2 && i + j != 2 * n)
			{
				a[i][j] = ((1LL * i) & 1) << (i + j - 3);
			}
			printf("%lld%c", a[i][j], " \n"[j == n]);
		}
	}
	cout << endl;
	int q;
	cin >> q;
	while (q--)
	{
		LL val;
		cin >> val;
		int dx[] = { 0,1 };
		int dy[] = { 1,0 };
		int x = 1, y = 1;
		while (x != n || y != n)
		{
			cout << x << ' ' << y << '\n';
			int len = (x + y + 1) - 3;
			for (int o = 0; o < 2; o++)
			{
				int tx = x + dx[o];
				int ty = y + dy[o];
				if (a[tx][ty] == -1) continue;
				int o1 = val >> len & 1;
				int o2 = a[tx][ty] >> len & 1;
				if (o1 == o2)
				{
					x = tx, y = ty;
					break;
				}
			}
		}
		cout << x << ' ' << y << endl;
	}
	return 0;
}