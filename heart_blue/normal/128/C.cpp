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
const int N = 1e3 + 10;
LL dp[N][N];
LL a[N];
void init()
{
	for (int i = 1; i < N; i++) dp[0][i] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++) a[j] = dp[i - 1][j];
		for (int j = 1; j < N; j++) a[j] = (a[j] + a[j - 1]) % INF;
		for (int j = 1; j < N; j++) a[j] = (a[j] + a[j - 1]) % INF;
		for (int j = 3; j < N; j++)
		{
			dp[i][j] = a[j - 2];
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, m, k;
	cin >> n >> m >> k;
	cout << dp[k][n] * dp[k][m] % INF << endl;
	return 0;
}