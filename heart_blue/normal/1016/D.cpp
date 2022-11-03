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
const int N = 3e2 + 10;
int a[N];
int b[N];
int ans[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int xor1 = 0;
	int xor2 = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		ans[i][1] = x;
		if (i > 1) xor1 ^= x;
		else xor2 ^= x;
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		ans[1][i] = x;
		if(i > 1) xor2 ^= x;
		else xor1 ^= x;
	}
	if (xor1 != xor2)
	{
		puts("NO");
		return 0;
	}
	ans[1][1] = xor1;
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d%c", ans[i][j], " \n"[j == m]);
		}
	}
	return 0;
}