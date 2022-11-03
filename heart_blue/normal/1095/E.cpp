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
const int N = 1e6 + 10;
int sum1[N];
int sum2[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	if (n & 1) puts("0"), exit(0);
	scanf("%s", str + 1);
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == '(') o++;
		else o--;
		if (o < 0) o = -INF;
		sum1[i] = o;
	}
	o = 0;
	for (int i = n; i > 0; i--)
	{
		if (str[i] == ')') o++;
		else o--;
		if (o < 0) o = -INF;
		sum2[i] = o;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sum1[i - 1] < 0 || sum2[i + 1] < 0) continue;
		int d = 1;
		if (str[i] == '(') d = 1;
		else d = -1;
		if (sum1[i - 1] - d == sum2[i + 1])
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}