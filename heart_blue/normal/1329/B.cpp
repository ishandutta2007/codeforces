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
const int N = 2e2 + 10;
LL dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int d, m;
		cin >> d >> m;
		d++;
		int o = 0;
		while ((1 << o) < d)
		{
			dp[o] = 1 << o;
			o++;
		}
		dp[o] = d;
		for (int i = o; i > 0; i--) dp[i] -= dp[i - 1];
		LL ans = 0;
		for (int i = 1; i <= o; i++)
		{
			LL sum = 0;
			for (int j = 0; j < i; j++) sum += dp[j];
			sum %= m;
			dp[i] = dp[i] * sum % m;
			ans += dp[i];
		}
		cout << ans % m << endl;
	}
	return 0;
}