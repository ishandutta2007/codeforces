#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

const int MAXN = 1000005;

int n,a,b;
int x[MAXN];
int MX[MAXN];
int f[MAXN];
int MN[MAXN];

void setv(int o,int l,int r,int p,int v)
{
	if (l == r)
	{
		MN[o] = v;
		return;
	}
	int mid = l + r >> 1;
	if (mid >= p)
		setv(o << 1,l,mid,p,v);
	else
		setv(o << 1 | 1,mid + 1,r,p,v);
	MN[o] = min(MN[o << 1],MN[o << 1 | 1]);
}

int query(int o,int l,int r,int x,int y)
{
	if (x > y)
		return 1e9;
	if (l >= x && r <= y)
		return MN[o];
	int mid = l + r >> 1;
	if (mid < x)
		return query(o << 1 | 1,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(o << 1,l,mid,x,y);
	return min(query(o << 1,l,mid,x,y),query(o << 1 | 1,mid + 1,r,x,y));
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&x[i]);
	sort(x + 1,x + n + 1);
	n = unique(x + 1,x + n + 1) - x - 1;
	scanf("%d%d",&b,&a);
	for (int i = 1;i <= n;i++)
		for (int j = b / x[i] * x[i];j >= a;j -= x[i])
			MX[b - j] = x[i];
	f[0] = 0;
	for (int i = 1;i <= b - a;i++)
	{
		f[i] = min(f[i - 1],query(1,0,b - a,max(0,i - MX[i] + 1),i - 1)) + 1;
		setv(1,0,b - a,i,f[i]);
	}
	printf("%d\n",f[b - a]);
	return 0;
}