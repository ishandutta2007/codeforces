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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
bool dp[N][N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j <= k; j++)
		{
			for (int t = 0; t <= k; t++)
			{
				dp[i][j][t] |= dp[i - 1][j][t];
				if (j >= x) dp[i][j][t] |= dp[i - 1][j - x][t];
				if (j >= x && t >= x) dp[i][j][t] |= dp[i - 1][j - x][t - x];
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i <= k; i++) if (dp[n][k][i]) ans.push_back(i);
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}