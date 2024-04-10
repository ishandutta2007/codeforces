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
const int N = 1e2 + 10;
tuple<int, int, int, int> dp[N][N][N];
char s1[N], s2[N], s3[N];
int fail[N];
void getfail(int n)
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j > 0 && s3[j + 1] != s3[i]) j = fail[j];
		if (s3[j + 1] == s3[i]) j++;
		fail[i] = j;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
	int n1 = strlen(s1 + 1);
	int n2 = strlen(s2 + 1);
	int n3 = strlen(s3 + 1);
	getfail(n3);
	//MEM(dp, -INF);
	dp[0][0][0] = dp[0][1][0] = dp[1][0][0] = { 0,0,0,0 };
	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			for (int k = 0; k < n3; k++)
			{
				dp[i][j][k] = max(dp[i][j][k], { get<0>(dp[i - 1][j][k]),i - 1,j,k });
				dp[i][j][k] = max(dp[i][j][k], { get<0>(dp[i - 1][j - 1][k]),i - 1,j - 1,k });
				dp[i][j][k] = max(dp[i][j][k], { get<0>(dp[i][j - 1][k]),i,j - 1,k });
				if (s1[i] == s2[j])
				{
					int o = k;
					while (o > 0 && s3[o + 1] != s1[i]) o = fail[o];
					if (s3[o + 1] == s1[i]) o++;
					int tot, x, y, z;
					tie(tot, x, y, z) = dp[i - 1][j - 1][k];
					dp[i][j][o] = max(dp[i][j][o], make_tuple(tot + 1, i - 1, j - 1, k));
				}
			}
		}
	}
	int x = n1, y = n2, z = 0;
	for (int i = 0; i < n3; i++)
	{
		if (dp[n1][n2][z] < dp[n1][n2][i])
			z = i;
	}
	int tot = get<0>(dp[n1][n2][z]);
	string ans;
	while (x > 0 || y > 0)
	{
		char c = s1[x];
		tie(ignore, x, y, z) = dp[x][y][z];
		if (tot > get<0>(dp[x][y][z]))
			ans.push_back(c), tot--;
	}
	if (ans.empty()) ans = "0";
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}