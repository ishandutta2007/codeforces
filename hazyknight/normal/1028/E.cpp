#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
int a[MAXN];

ll sum;
ll b[MAXN];

int main()
{
	scanf("%d",&n);
	int MAX = 0,zero = 0;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		MAX = max(MAX,a[i]);
		sum += a[i];
		zero += !a[i];
	}
	if (MAX == 0)
	{
		puts("YES");
		for (int i = 1;i <= n;i++)
			printf("1 ");
		printf("\n");
		return 0;
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		if (a[i] == MAX)
			cnt++;
	if (cnt == n)
	{
		puts("NO");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		if (a[i] == MAX && a[i == 1 ? n : i - 1] != a[i])
		{
			if (cnt + zero == n)
				sum = sum + MAX;
			b[i % n + 1] = sum;
			for (int j = i + 2;j <= n;j++)
				b[j] = b[j - 1] - a[j - 1];
			if (i != n)
				b[1] = b[n] - a[n];
			for (int j = 2;j <= i;j++)
				b[j] = b[j - 1] - a[j - 1];
			if (cnt + zero == n)
				b[i] -= MAX;
			break;
		}
	puts("YES");
	for (int i = 1;i <= n;i++)
		printf("%lld ",b[i]);
	printf("\n");
	return 0;
}