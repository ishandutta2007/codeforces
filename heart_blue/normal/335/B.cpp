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
const int N = 3e3 + 10;
tuple<int,int,int> dp[N][N];
char str[N * 100];
int cnt[N];
void solve(int l, int r)
{
	string ans1;
	string ans2;
	int key = 0;
	while (1)
	{
		tie(key, l, r) = dp[l][r];
		if (key == 0) break;
		ans1.push_back(str[l]);
		if (l != r) ans2.push_back(str[r]);
		if (ans1.length() + ans2.length() == 100) break;
		l++, r--;
	}
	reverse(ans2.begin(), ans2.end());
	cout << ans1 << ans2 << '\n';
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
	{
		cnt[str[i]]++;
		if (cnt[str[i]] == 100)
		{
			cout << string(100, str[i]) << endl;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = make_tuple(1, i, i);
	}
	for (int i = 1; i < n; i++)
	{
		if (str[i] == str[i + 1])
			dp[i][i + 1] = make_tuple(2, i, i + 1);
		else
			dp[i][i + 1] = dp[i][i];
	}
	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len <= n; i++)
		{
			int j = i + len;
			dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			if (str[i] == str[j])
			{
				int res, l, r;
				tie(res, l, r) = dp[i + 1][j - 1];
				dp[i][j] = max(dp[i][j], make_tuple(res + 2, i, j));
			}
			if (get<0>(dp[i][j]) >= 100)
				solve(i, j);
		}
	}
	solve(1, n);
	return 0;
}