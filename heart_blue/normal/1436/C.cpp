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
const int N = 2e3 + 10;
int a[N][N];
void init()
{
	for (int i = 0; i < N; i++) a[i][0] = a[i][i] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			if (a[i][j] >= INF)
				a[i][j] -= INF;
		}
	}
}
int fact(int n)
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret = 1LL * i * ret % INF;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, x, pos;
	scanf("%d%d%d", &n, &x, &pos);
	int l = 0, r = n;
	int cnt0 = 0, cnt1 = 0;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (mid <= pos) l = mid + 1, cnt0++;
		else r = mid, cnt1++;
	}
	cnt0--;
	LL ans = 1LL * a[x - 1][cnt0] * a[n - x][cnt1] % INF * fact(cnt0) % INF * fact(cnt1) % INF * fact(n - 1 - cnt0 - cnt1) % INF;
	printf("%lld\n", ans);
	return 0;
}