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
const int N = 2e6 + 10;
const int K = 19;
int p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 };
int mask[71];
int cnt[71];
LL dp[2][N];
int p2[N];
void init()
{
	p2[0] = 1;
	for (int i = 1; i < N; i++) p2[i] = p2[i - 1] * 2 % INF;
	for (int i = 1; i <= 70; i++)
	{
		for (int j = 0; j < K && p[j] <= i; j++)
		{
			int o = 0;
			int x = i;
			while (x%p[j] == 0) x /= p[j], o ^= 1;
			mask[i] |= o << j;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	scanf("%d", &n);
	MEM(dp, 0);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int o = 0;
	for (int i = 1; i <= 70; i++)
	{
		if (cnt[i] == 0) continue;
		o ^= 1;
		memcpy(dp[o], dp[o ^ 1], sizeof(dp[o]));
		LL odd = p2[cnt[i] - 1];
		LL even = odd - 1;
		for (int j = 0; j < (1 << 20); j++)
		{
			dp[o][j] = (dp[o][j] + dp[o ^ 1][j] * even + dp[o ^ 1][j^mask[i]] * odd) % INF;
		}
		dp[o][0] = (dp[o][0] + even) % INF;
		dp[o][mask[i]] = (dp[o][mask[i]] + odd) % INF;
	}
	cout << dp[o][0] << endl;
	return 0;
}