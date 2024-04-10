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
int dp[N][N];
int dp1[N][N][N];
int fail[N];
char str[N];
int flag[N];
int nex[N][N];
void getfail(int sz)
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= sz; i++)
	{
		while (j > 0 && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) j++;
		fail[i] = j;
	}
	for (int o = 1; o < sz; o++)
	{
		int j = o;
		for (int i = 1; i < sz; i++)
		{
			while (j > 0 && str[j + 1] != str[i]) j = fail[j];
			if (str[j + 1] == str[i]) j++;
			if (j == sz)
			{
				flag[o] = 1;
				break;
			}
		}
	}
	//int o = sz;
	//while (o)
	//{
	//	flag[o] = 1;
	//	o = fail[o];
	//}
}
int getnext(int cur, char c)
{
	if (nex[cur][c] != -1) return nex[cur][c];
	int &tmp = nex[cur][c];
	while (cur != 0 && str[cur + 1] != c) cur = fail[cur];
	if (str[cur + 1] == c) cur++;
	return tmp = cur;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(nex, -1);
	dp[0][0] = 1;
	int n;
	cin >> n;
	n *= 2;
	scanf("%s", str + 1);
	int sz = strlen(str + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j > 0) dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i - 1][j + 1];
			if (dp[i][j] >= INF) dp[i][j] -= INF;
		}
	}
	int minv = 0;
	int o = 0;
	for (int i = 1; i <= sz; i++)
	{
		char c = str[i];
		if (c == '(') o++;
		else o--;
		minv = min(minv, o);
	}
	minv = -minv;
	getfail(sz);
	dp1[0][0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				if (k > 0)
				{
					int o = getnext(j, ')');
					int &tmp = dp1[i + 1][o][k - 1] += dp1[i][j][k];
					if (tmp >= INF) tmp -= INF;
				}
				int o = getnext(j, '(');
				int &tmp = dp1[i + 1][o][k + 1] += dp1[i][j][k];
				if (tmp >= INF) tmp -= INF;
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i <= n - sz; i++)
	{
		int r = n - sz - i;
		for (int j = 0; j < sz; j++)
		{
			if (flag[j]) continue;
			for (int k = minv; k <= n && k +o <= n; k++)
			{
				ans = (ans + 1LL * dp1[i][j][k] * dp[r][k + o]) % INF;
			}
		}
	}
	cout << ans << endl;
	return 0;
}