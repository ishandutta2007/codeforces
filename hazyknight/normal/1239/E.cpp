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

const int MAXN = 51;
const int MAXM = 1250005;

int n,tot,ans = 1e9,A,B,Y;
int a[MAXN];
int up[MAXN];
int dn[MAXN];

ll f[25][MAXM];

void add(int v)
{
	for (int i = n - 1;i >= 1;i--)
	{
		int c = max(0,(tot >> 1) - v + 1);
		ll *A = f[i] + v,*B = f[i - 1];
		while (c--)
			*(A++) += *(B++);
	}
}

void ers(int v)
{
	for (int i = 1;i < n;i++)
	{
		int c = max(0,(tot >> 1) - v + 1);
		ll *A = f[i] + v,*B = f[i - 1];
		while (c--)
			*(A++) -= *(B++);
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= 2 * n;i++)
	{
		scanf("%d",&a[i]);
		tot += a[i];
	}
	sort(a + 1,a + 2 * n + 1);
	tot -= a[1] + a[2];
	f[0][0] = 1;
	for (int i = 3;i <= 2 * n;i++)
		add(a[i]);
	for (int j = (tot >> 1);j >= 0;j--)
		if (f[n - 1][j])
		{
			Y = j;
			break;
		}
	int cnt = n - 1;
	for (int i = 3;i <= 2 * n;i++)
	{
		ers(a[i]);
		if (f[cnt][Y])
			dn[++B] = a[i];
		else
		{
			up[++A] = a[i];
			Y -= a[i];
			cnt--;
		}
	}
	printf("%d ",a[1]);
	for (int i = 1;i <= A;i++)
		printf("%d ",up[i]);
	printf("\n");
	for (int i = B;i >= 1;i--)
		printf("%d ",dn[i]);
	printf("%d\n",a[2]);
	return 0;
}