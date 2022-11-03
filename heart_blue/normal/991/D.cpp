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
const int N = 1e5 + 10;
int dp[N][4];
string s1, s2;
vector<pair<int,int>> v[4];
int check(char c1, char c2)
{
	return (c1 == 'X') << 1 | (c2 == 'X');
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s1 >> s2;
	int n = s1.length();
	s1 = "X" + s1;
	s2 = "X" + s2;
	MEM(dp, 0xef);
	dp[0][3] = 0;
	v[0] = { {1,3},{2,3},{0,1},{0,2},{0,3} };
	v[1] = { {0,3} };
	v[2] = { {0,3} };
	for (int i = 1; i <= n; i++)
	{
		int o = check(s1[i], s2[i]);
		//cout << o << endl;
		for (int j = 0; j < 4; j++)
		{
			dp[i][o] = max(dp[i][o], dp[i - 1][j]);
		}
		for (auto &p : v[o])
		{
			int y, oo;
			tie(y, oo) = p;
			dp[i][oo] = max(dp[i][oo], dp[i - 1][y] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}