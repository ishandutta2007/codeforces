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
const int N = 2e3 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> m >> n >> k;
	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][j];
		}
	}
	pair<int, int> ans = { 0,0 };
	for (int i = 1; i <= n; i++)
	{
		int cost = 0;
		pair<int, int> tmp = { 0,0 };
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 0) continue;
			int cnt = 0;
			for (int t = j; t <= min(m, j + k - 1); t++)
			{
				if (a[i][t] == 1) cnt++;
			}
			tmp = max(tmp, { cnt,-cost });
			cost++;
		}
		ans = { ans.first + tmp.first,ans.second + tmp.second };
	}
	printf("%d %d\n", ans.first, -ans.second);
	return 0;
}