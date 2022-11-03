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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
LL dp[N];
LL ans[N];
void init()
{
	for (int i = 2; i <= 62; i++)
	{
		MEM(dp, 0);
		for (int j = 1; j < i; j++)
		{
			if (i % j) continue;
			dp[j] = 1LL << (j - 1);
			for (int k = 1; k < j; k++)
			{
				if (j % k) continue;
				dp[j] -= dp[k];
			}
			ans[i] += dp[j];
		}
	}
}
LL solve(LL x)
{
	if (x <= 2) return 0;
	string str;
	while (x)
	{
		str += x % 2 + '0';
		x >>= 1;
	}
	reverse(str.begin(), str.end());
	LL ret = 0;
	int n = str.length();
	for (int i = 1; i < n; i++)
		ret += ans[i];
	MEM(dp, 0);
	for (int i = 1; i < n; i++)
	{
		if (n % i) continue;
		string key;
		while (key.length() < n)
			key += str.substr(0, i);
		LL tot = 0;
		if (key <= str) tot++;
		string minv = str.substr(0, i);
		minv[0] = '0';
		tot += stoll(minv, nullptr, 2);
		dp[i] = tot;
		for (int j = 1; j < i; j++)
		{
			if (i % j) continue;
			dp[i] -= dp[j];
		}
		ret += dp[i];
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	LL l, r;
	cin >> l >> r;
	cout << solve(r) - solve(l - 1) << endl;
	return 0;
}