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
const int N = 1e2 + 10;
int a[N];
int flag[N];
void init()
{
	MEM(flag, 0);
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		for (int j = i + i; j < N; j += i) flag[j] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		a[i] = flag[i];
		for (int j = 1; j < i; j++)
		{
			if (a[j] && flag[i - j]) a[i] = max(a[i], 1 + a[j]);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int tot = n/4;
		int ans = -1;
		int o = n % 4;
		for (int i = 0; i <= min(25, tot); i++)
		{
			if (a[o + i * 4])
				ans = max(ans, a[o + i * 4] + tot - i);
		}
		printf("%d\n", ans);
	}
	return 0;
}