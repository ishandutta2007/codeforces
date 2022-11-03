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
const int N = 2e2 + 10;
int dp[3][N];
char str[3][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int len, n;
		cin >> len >> n;
		MEM(str, '.');
		MEM(dp, 0);
		for (int i = 0; i < 3; i++)
		{
			cin >> str[i];
			if (str[i][0] == 's')
			{
				dp[i][0] = 1;
			}
		}
		for (int j = 0; j < len; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (dp[i][j] == 0) continue;
				if (isalpha(str[i][j + 1])) continue;
				for (int o = -1; o <= 1; o++)
				{
					int k = o + i;
					if (k >= 3) continue;
					if (k < 0) continue;
					int flag = 1;
					for (int s = 1; s <= 3; s++)
					{
						if (isalpha(str[k][j + s]))
						{
							flag = 0;
							break;
						}
					}
					dp[k][j + 3] = flag;
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = len; j < len + 10; j++)
			{
				flag |= dp[i][j];
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}