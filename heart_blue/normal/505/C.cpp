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
const int N = 3e4 + 10;
const int M = 5e2 + 10;
int dp[N][M];
int a[N];
int step[N];
map<string, int> ans;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, d;
	cin >> n >> d;
	int sum = 0;
	int l = d;
	while (l > 0 && sum + l <= N) sum += l--;
	l++;
	int r = d;
	sum = 0;
	while (r < N && sum + r <= N) sum += r++;
	r--;
	int k = r - l;
	for (int i = 0; i <= k; i++) step[i] = (i + l);
	MEM(dp, 0);
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		len = x;
		a[x]++;
	}
	dp[d][d-step[0]] = 1;
	int ans = 0;
	for (int i = d; i <= len; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (dp[i][j] == 0) continue;
			dp[i][j] += a[i];
			for (int o = j - 1; o <= j + 1; o++)
			{
				if (o < 0) continue;
				if (o > k) continue;
				if (i + step[o] > len) continue;
				int &tmp = dp[i + step[o]][o];
				tmp = max(tmp, dp[i][j]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	ans -= 1;
	cout << ans << endl;

	return 0;
}