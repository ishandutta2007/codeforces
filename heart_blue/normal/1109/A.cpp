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
const int N = 2e6 + 10;
int flag[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	flag[0][0] = 1;
	int sum = 0;
	int n;
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sum ^= x;
		if (i == 1)
		{
			flag[1][x] = 1;
			continue;
		}
		ans += flag[i & 1][sum]++;
	}
	printf("%lld\n", ans);
	return 0;
}