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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e4 + 10;
const int M = 600;
int dp[N][M];
map<int, int> mc;

void init()
{
	for (int i = 0; i < M; i++) dp[i][i] = 1;
	for (int i = 0; i < N; i++) dp[i][0] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < min(M, i); j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			if (dp[i][j] >= INF)
			{
				dp[i][j] -= INF;
			}
		}
	}
}
void check(int x)
{
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i) continue;
		int cnt = 0;
		while (x%i == 0) cnt++, x /= i;
		mc[i] += cnt;
	}
	if (x > 1) mc[x]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		check(x);
	}
	init();
	LL ans = 1;
	for (auto &p : mc)
	{
		ans = ans * dp[p.second + n - 1][n - 1] % INF;
	}
	cout << ans << endl;
	return 0;
}