#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
LL x[10],y[10],z[10];
int flag;
inline LL sqr(LL p) { return p*p;}
inline void check()
{
	LL x1=0,y1=0,x2=0,y2=0,x3=0,y3=0;
	for (int i=1;i<=7;i++)
	for (int j=i+1;j<=8;j++)
	{
		LL p=sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]);
		if (p==0) return;
		if (p==x1||x1==0) { x1=p; y1++;continue;}
		if (p==x2||x2==0) { x2=p; y2++;continue;}
		if (p==x3||x3==0) { x3=p; y3++;continue;}
		return;
	}
	if (x1>x2) swap(x1,x2),swap(y1,y2);
	if (x1>x3) swap(x1,x3),swap(y1,y3);
	if (x2>x3) swap(x2,x3),swap(y2,y3);
	if (3*x1!=x3) return;
	if (2*x1!=x2) return;
	if (y1!=12||y2!=12||y3!=4) return;
	flag=1;
	printf("YES\n");
	for (int i=1;i<=8;i++) printf("%I64d %I64d %I64d\n",x[i],y[i],z[i]);
}
void dfs(int i)
{
	if (flag) return;
	if (i==9) { check();return;}
	dfs(i+1);
	swap(y[i],z[i]);dfs(i+1);
	swap(x[i],z[i]);dfs(i+1);
	swap(y[i],z[i]);dfs(i+1);
	swap(x[i],z[i]);dfs(i+1);
	swap(y[i],z[i]);dfs(i+1);
}
int main()
{
	flag=0;
	for (int i=1;i<=8;i++) scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
	dfs(1);
	if (!flag)  printf("NO\n");
}