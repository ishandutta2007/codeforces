#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int l[100100], r[100100], d[100100], e[100100], a[100100];
long long f[100100];

int main()
{
	int x, y, n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", l + i, r + i, d + i);
	while (k--)
	{
		scanf("%d%d", &x, &y);
		e[x]++; e[y + 1]--;
	}
	
	for (int i = 1; i <= m; i++) 
	{
		e[i] += e[i - 1];
		f[l[i]] += 1LL * e[i] * d[i];
		f[r[i] + 1] -= 1LL * e[i] * d[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		f[i] += f[i - 1];
		printf("%I64d ", f[i] + a[i]);
	}
	puts("");
}