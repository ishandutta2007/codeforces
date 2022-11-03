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
const int N = 1e2 + 10;
int n, m, k1, k2;
int dp[N][N][2];
const int mod = 1e8;
int getans(int a, int b, int o)
{
	if (dp[a][b][o] != -1) return dp[a][b][o];
	int &t = dp[a][b][o] = 0;
	if (o)
	{
		for (int i = 1; i <= min(a,k1); i++)
		{
			t += getans(a - i, b, o ^ 1);
			if (t >= mod) t -= mod;
		}
	}
	else
	{
		for (int i = 1; i <= min(b,k2); i++)
		{
			t += getans(a, b - i, o^1);
			if (t >= mod) t -= mod;
		}
	}
	return t;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	MEM(dp, -1);
	dp[0][0][0] = dp[0][0][1] = 1;
	cin >> n >> m >> k1 >> k2;
	cout << (getans(n, m, 1) + getans(n, m, 0)) % LL(1e8) << endl;
	return 0;
}