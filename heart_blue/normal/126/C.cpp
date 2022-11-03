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
const int N = 2e3 + 10;
char str[N][N];
int sum1[N][N];
int sum2[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	int ans = 0;
	for (int o = n - 1; o > 0; o--)
	{
		for (int i = 1; i + o <= n; i++)
		{
			int j = i + o;
			sum1[i][j] ^= sum1[i - 1][j];
			sum2[i][j] ^= sum2[i][j + 1];
			if ((str[i][j] - '0') ^ sum1[i][j] ^ sum2[i][j])
			{
				ans++;
				sum1[i][j] ^= 1;
				sum2[i][j] ^= 1;
			}
			str[i][j] = '0';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sum1[i][i] ^= sum1[i - 1][i];
		sum2[i][i] ^= sum2[i][i + 1];
		str[i][i] ^= sum1[i][i] ^ sum2[i][i];
	}
	MEM(sum1, 0);
	MEM(sum2, 0);
	for (int o = n - 1; o > 0; o--)
	{
		for (int i = n; i - o >= 1; i--)
		{
			int j = i - o;
			sum1[i][j] ^= sum1[i + 1][j];
			sum2[i][j] ^= sum2[i][j - 1];
			if ((str[i][j] - '0') ^ sum1[i][j] ^ sum2[i][j])
			{
				ans++;
				sum1[i][j] ^= 1;
				sum2[i][j] ^= 1;
			}
			str[i][j] = '0';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sum1[i][i] ^= sum1[i + 1][i];
		sum2[i][i] ^= sum2[i][i - 1];
		str[i][i] ^= sum1[i][i] ^ sum2[i][i];
		ans += str[i][i] - '0';
	}
	printf("%d\n", ans);
	return 0;
}