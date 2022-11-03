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
const int N = 5e3 + 10;
char c[N][100];
vector<pair<int, int>> vp[3];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int m = 12;
	for (int i = 1; i <= n; i++) cin >> (c[i] + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == '.')
			{
				int cnt = 0;
				cnt += c[i][j - 1] == 'S';
				cnt += c[i][j + 1] == 'S';
				vp[cnt].push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		while (k > 0 && !vp[i].empty())
		{
			int x, y;
			tie(x, y) = vp[i].back();
			vp[i].pop_back();
			c[x][y] = 'x';
			k--;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == 'S')
			{
				if (isalnum(c[i][j - 1])) ans++;
				if (isalnum(c[i][j + 1])) ans++;
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) puts(c[i] + 1);
	return 0;
}