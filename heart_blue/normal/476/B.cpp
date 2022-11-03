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
const int N = 100;

double dp[2][N+2];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	
	int s = 50;
	int t = 50;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+') t++;
		else t--;
	}
	for (int i = 0; i < N+2; i++) dp[0][i] = dp[1][i] = 0;
	cin >> str;
	dp[0][s] = 1;
	for (int i = 0; i < str.length(); i++)
	{
		int t = i & 1;
		if (str[i] == '+')
		{
			for (int j = 1; j < N; j++) dp[t ^ 1][j] = dp[t][j - 1];
		}
		if (str[i] == '-')
		{
			for (int j = 1; j < N; j++) dp[t ^ 1][j] = dp[t][j + 1];
		}
		if (str[i] == '?')
		{
			for (int j = 1; j < N; j++) dp[t ^ 1][j] = (dp[t][j - 1] + dp[t][j + 1]) / 2.0;
		}

	}
	printf("%.12f\n", dp[str.length() & 1][t]);
	return 0;
}