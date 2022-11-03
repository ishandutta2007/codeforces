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
const int N = 1e3 + 10;
int sum[N];
char str[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		for (int i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + (str[i] - '0');
		}
		int ans = min(sum[n], n - sum[n]);
		for (int i = 1; i <= n; i++)
		{
			int res = min(sum[i] + n - i - (sum[n] - sum[i]), i - sum[i] + sum[n] - sum[i]);
			ans = min(ans, res);
		}
		printf("%d\n", ans);
	}
	return 0;
}