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
const int N = 2e2 + 10;
char str[N];
int fail[N];
int nex[N][N];
pair<int, int> pre[N][N];
int dp[N][N];
int flag[N];
void getfail(char str[N], int n)
{
	int j = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) j++;
		fail[i] = j;
	}
	for (int i = 0; i < n; i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			if (str[i + 1] == c) nex[i][c] = i + 1;
			else nex[i][c] = nex[fail[i]][c];
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str + 1);
	int m = strlen(str + 1);
	getfail(str, m);
	string s;
	cin >> s;
	MEM(flag, -1);
	for (int i = 0; i < s.length(); i++)
	{
		flag[i + m] = s[i] - '0';
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dp[i][j] == 0) continue;
			for (int t = 0; t < k; t++)
			{
				char c = 'a' + t;
				int o = nex[j][c];
				if (flag[i + 1] == 1 && o != m) continue;
				if (flag[i + 1] == 0 && o == m) continue;
				if (o == m)
				{
					o = fail[o];
				}
				dp[i + 1][o] = 1;
				pre[i + 1][o] = { j,c };
			}
		}
	}
	int o = -1;
	for (int i = 0; i < m; i++)
	{
		if (dp[n][i])
		{
			o = i;
			break;
		}
	}
	if (o == -1)
	{
		puts("No solution");
		return 0;
	}
	string ans;
	for (int i = n; i >= 1; i--)
	{
		int c;
		tie(o, c) = pre[i][o];
		ans += c;
	}
	reverse(ans.begin(), ans.end());
	puts(ans.c_str());
	return 0;
}