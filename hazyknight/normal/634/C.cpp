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

const int MAXN = 200005;

int n,k,a,b,q;
int cnt[MAXN];
int sum1[MAXN];
int sum2[MAXN];

void modify(int *sum,int p,int v)
{
	while (p <= n)
	{
		sum[p] += v;
		p += p & -p;
	}
}

int query(int *sum,int p)
{
	int res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

int main()
{
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	for (int tp,d,A,p,i = 1;i <= q;i++)
	{
		scanf("%d",&tp);
		if (tp == 1)
		{
			scanf("%d%d",&d,&A);
			modify(sum1,d,min(A,max(0,b - cnt[d])));
			modify(sum2,d,min(A,max(0,a - cnt[d])));
			cnt[d] += A;
		}
		else
		{
			scanf("%d",&p);
			int ed = min(n,p + k - 1);
			printf("%d\n",query(sum1,p - 1) + query(sum2,n) - query(sum2,ed));
		}
	}
	return 0;
}