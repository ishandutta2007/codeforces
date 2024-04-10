#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int n,tot;
int a[MAXN];
int pos[MAXN];
int ans[MAXN * 5][2];

void go(int i,int j)
{
	tot++;
	ans[tot][0] = i;
	ans[tot][1] = j;
	swap(a[i],a[j]);
	swap(pos[a[i]],pos[a[j]]);
}

void swp(int i,int j)
{
	if (i == j)
		return;
	if (abs(i - j) >= n / 2)
	{
		go(i,j);
		return;
	}
	if (i <= n / 2)
	{
		if (j <= n / 2)
		{
			go(i,n);
			go(j,n);
			go(i,n);
		}
		else
		{
			go(i,n);
			go(j,1);
			go(1,n);
			go(i,n);
			go(j,1);
		}
	}
	else
	{
		if (j <= n / 2)
		{
			go(i,1);
			go(j,n);
			go(1,n);
			go(i,1);
			go(j,n);
		}
		else
		{
			go(1,i);
			go(1,j);
			go(1,i);
		}
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]] = i;
	}
	for (int i = 1;i <= n;i++)
		swp(pos[i],i);
	printf("%d\n",tot);
	for (int i = 1;i <= tot;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}