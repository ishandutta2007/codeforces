#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n,dif,odd,neg;
int a[MAXN];
int cnt[MAXN];

ll ans;

void add(int p,int v)
{
	odd -= cnt[p] & 1;
	neg -= cnt[p] < 0;
	cnt[p] += v;
	odd += cnt[p] & 1;
	neg += cnt[p] < 0;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1,j = n;i < j;i++,j--)
		if (a[i] != a[j])
			dif++;
	for (int i = 1,j = 1;i <= n;i++)
	{
		if (n - i + 1 > i)
		{
			if (a[i] != a[n - i + 1])
				dif--;
			add(a[i],1);
			add(a[n - i + 1],-1);
		}
		else if (i == n - i + 1)
			add(a[i],1);
		else if (n - i + 1 >= j)
			add(a[i],2);
		else
		{
			if (a[i] != a[n - i + 1])
				dif--;
			add(a[i],1);
			add(a[n - i + 1],-1);
		}
		while (j <= i && !dif && odd <= 1 && !neg)
		{
			if (n - j + 1 < j)
			{
				if (a[j] != a[n - j + 1])
					dif++;
				add(a[n - j + 1],1);
				add(a[j],-1);
			}
			else if (j == n - j + 1)
				add(a[j],-1);
			else if (n - j + 1 <= i)
				add(a[j],-2);
			else
			{
				if (a[j] != a[n - j + 1])
					dif++;
				add(a[n - j + 1],1);
				add(a[j],-1);
			}
			j++;
		}
		ans += j - 1;
	}
	printf("%lld\n",ans);
    return 0;
}