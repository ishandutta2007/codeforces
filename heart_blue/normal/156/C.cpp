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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int dp[101][3000];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[0][0] = 1;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 3000; j++)
		{
			if (dp[i][j] == 0) continue;
			for (int k = 0; k < 26; k++)
			{
				int& tmp = dp[i + 1][j + k] += dp[i][j];
				if (tmp >= INF) tmp -= INF;
			}
		}
	}
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string str;
		cin >> str;
		int tot = 0;
		for (auto& c : str)
			tot += c - 'a';
		int ans = dp[str.length()][tot] - 1;
		if (ans < 0) ans += INF;
		printf("%d\n", ans);
	}
	return 0;
}