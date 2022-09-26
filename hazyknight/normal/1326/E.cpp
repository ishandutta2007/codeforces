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

const int MAXN = 300005;
const int INF = 1e9;

struct Mat
{
	int r,c;
	int a[2][2];
	
	Mat (int R = 0,int C = 0)
	{
		r = R;
		c = C;
		a[0][0] = a[0][1] = a[1][0] = a[1][1] = -INF;
	}
	
	Mat operator * (const Mat &p)const
	{
		Mat res(r,p.c);
		for (int i = 0;i < r;i++)
			for (int j = 0;j < p.c;j++)
				for (int k = 0;k < c;k++)
					res.a[i][j] = max(res.a[i][j],a[i][k] + p.a[k][j]);
		return res;
	}
}sum[MAXN << 2],init = Mat(1,2);

int n;
int p[MAXN];
int q[MAXN];
int v[MAXN];
int pos[MAXN];

void buildtree(int o,int l,int r)
{
	if (l == r)
	{
		sum[o] = Mat(2,2);
		sum[o].a[1][0] = sum[o].a[1][1] = sum[o].a[0][0] = 0;
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	sum[o] = sum[o << 1] * sum[o << 1 | 1];
}

void modify(int o,int l,int r,int p)
{
	if (l == r)
	{
		sum[o] = Mat(2,2);
		sum[o].a[1][0] = sum[o].a[1][1] = 0;
		sum[o].a[0][0] = v[l];
		return;
	}
	int mid = l + r >> 1;
	if (mid >= p)
		modify(o << 1,l,mid,p);
	else
		modify(o << 1 | 1,mid + 1,r,p);
	sum[o] = sum[o << 1] * sum[o << 1 | 1];
}

int main()
{
	init.a[0][0] = init.a[0][1] = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]] = i;
	}
	for (int i = 1;i <= n;i++)
		scanf("%d",&q[i]);
	buildtree(1,1,n);
	printf("%d ",n);
	v[pos[n]]++;
	modify(1,1,n,pos[n]);
	for (int i = 1,j = n;i < n;i++)
	{
		v[q[i]]--;
		modify(1,1,n,q[i]);
		while (!(init * sum[1]).a[0][0])
		{
			v[pos[--j]]++;
			modify(1,1,n,pos[j]);
		}
		printf("%d ",j);
	}
	printf("\n");
	return 0;
}