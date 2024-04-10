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
const int N = 1e4 + 10;
int dp[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int tot = 0;
	int cur = 0;
	string str;
	while (cin >> str)
	{
		cur += str.length() + (cur > 0);
		if (str.back() == '.' || str.back() == '?' || str.back() == '!')
		{
			a[++tot] = cur;
			if (cur > n)
			{
				puts("Impossible");
				return 0;
			}
			cur = 0;
		}
	}
	MEM(dp, 0x3f);
	dp[0] = 0;
	for (int i = 1; i <= tot; i++)
	{
		int sum = 0;
		for (int j = i; j > 0; j--)
		{
			sum += a[j] + (sum > 0);
			if (sum > n) break;
			dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}
	cout << dp[tot] << endl;
	return 0;
}