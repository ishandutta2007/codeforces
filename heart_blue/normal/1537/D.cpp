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
const int N = 1e6 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//for (int i = 1; i < 200; i++)
	//{
	//	for (int j = 2; j * j <= i; j++)
	//	{
	//		if(i%j) continue;
	//		if (dp[i - j] == 0 || dp[i - i / j] == 0)
	//			dp[i] = 1;
	//	}
	//	if (dp[i] == 0) cout << i << endl;
	//}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		if (n % 2 == 1) puts("Bob");
		else if (n != (n & -n)) puts("Alice");
		else
		{
			int cnt = 0;
			while (n > 1) cnt++, n >>= 1;
			if (cnt & 1) puts("Bob");
			else puts("Alice");
		}
	}
	return 0;
}