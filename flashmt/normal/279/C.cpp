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
using namespace std;

int n, q, a[100100], d[100100], firstDif[100100], leftmostInc[100100], leftmostDec[100100];

int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	
	firstDif[1] = 1;
	for (int i = 2; i <= n; i++)
		if (a[i] == a[i - 1]) firstDif[i] = firstDif[i - 1];
		else firstDif[i] = i - 1;
	
	leftmostDec[1] = leftmostInc[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] <= a[i - 1]) leftmostInc[i] = leftmostInc[i - 1];
		if (a[i] >= a[i - 1]) leftmostDec[i] = leftmostDec[i - 1];
		if (a[i] < a[i - 1]) leftmostDec[i] = i;
		if (a[i] > a[i - 1]) leftmostInc[i] = i;
	}
		
	int x, y;
	while (q--)
	{
		scanf("%d%d", &x, &y);
		if (firstDif[y] <= x) puts("Yes");
		else
		{
			int z = firstDif[y];
			if (a[z] > a[y])
				puts(leftmostDec[leftmostInc[y]] <= x ? "Yes" : "No");
			else
				puts(leftmostDec[y] <= x ? "Yes" : "No");
		}
	}
}