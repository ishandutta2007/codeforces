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
char board[N][N];
int cur[N][N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	a['W'] = 1;
	a['B'] = -1;
	for (int i = 0; i < n; i++) cin >> board[i];
	MEM(cur, 0);
	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (a[board[i][j]] != cur[i][j])
			{
				ans++;
				int o = cur[i][j] - a[board[i][j]];
				for (int s = i; s >= 0; s--)
				{
					for (int t = j; t >= 0; t--)
					{
						cur[s][t] -= o;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}