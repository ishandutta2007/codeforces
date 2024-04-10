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
const int N = 1e7 + 10;
int d[N][3];
int a[N / 10];
int flag[N];
LL multy(LL x, LL y)
{
	if (x > INF*INF / y) return INF * INF;
	else return x * y;
}
void add(int a[3], int y)
{
	a[2] = y;
	if (a[1] > a[2]) swap(a[1], a[2]);
	if (a[0] > a[1]) swap(a[0], a[1]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(d, 0x3f);
	int n;
	scanf("%d", &n);
	for (int o = 1; o <= n; o++)
	{
		int x;
		scanf("%d", &x);
		a[o] = x;
		flag[x]++;
	}
	LL ans = INF * INF;
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
		{
			if (flag[j]) add(d[i], j / i);
			if (flag[j] > 1) add(d[i], j / i);
		}
	}
	for (int i = 1; i < N; i++)
	{
		ans = min(ans, multy(1LL * d[i][0] * d[i][1], i));
	}
	for (int i = 1, cnt = 0; cnt < 2 && i <= n; i++)
	{
		if (ans % a[i] == 0)
		{
			printf("%d ", i);
			cnt++;
		}
	}
	return 0;
}