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
const int N = 5e3 + 10;
char s1[N], s2[N];
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	s1[0] = '#';
	s2[0] = '*';
	scanf("%s%s", &s1[1], &s2[1]);
	int l1 = strlen(s1 + 1);
	int l2 = strlen(s2 + 1);
	MEM(dp, 0);
	LL ans = 0;
	for (int i = 1; i <= l1; i++)
	{
		int o = 1;
		for (int j = 1; j <= l2; j++)
		{
			if (s1[i] == s2[j])
			{
				dp[i][j] = o;
			}
			if (s1[i - 1] == s2[j])
			{
				o += dp[i - 1][j];
				if (o >= INF) o -= INF;
			}
			ans += dp[i][j];
		}
	}
	cout << ans % INF << endl;

	return 0;
}