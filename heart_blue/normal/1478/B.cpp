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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int k;
		scanf("%d", &k);
		MEM(dp, 0);
		dp[0] = 1;
		for (int i = 0; i < N; i++)
		{
			if (dp[i] == 0) continue;
			for (int j = 0; j < k; j++)
			{
				int x = j * 10 + k;
				if (i + x < N) dp[i + x] = 1;
			}
		}
		while (n--)
		{
			int x;
			scanf("%d", &x);
			if (x >= k * 10 || x % k == 0)
			{
				puts("YES");
				continue;
			}
			if (dp[x]) puts("YES");
			else puts("NO");
		}
	}

	return 0;
}