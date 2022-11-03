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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
char c[N][N];
int main()
{
	//freopen("lasers.in", "r", stdin);
	//freopen("lasers.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int l = INF, r = 0;
	int u = INF, d = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin >> ch;
			c[i][j] = ch;
			if (ch == 'X')
			{
				l = min(j, l);
				r = max(j, r);
				u = min(i, u);
				d = max(i, d);
			}
		}
	}
	int ans = (r - l + 1)*(d - u + 1);
	int sum = 0;
	for (int i = u; i <= d; i++)
	{
		for (int j = l; j <= r; j++)
		{
			if (c[i][j] == 'X') sum++;
		}
	}
	if (ans == sum) puts("YES");
	else puts("NO");
	return 0;
}