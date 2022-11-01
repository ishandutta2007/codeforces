#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100010;
struct rec {int x,y;};
int n,p;
int s[800],f[800],g[800];
rec a[N];
int cmp(rec a,rec b) { return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int main()
{
	scanf("%d%d",&n,&p);
	int m=sqrt(6*p)+5;
	for (int i=1;i<=p;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].x=n+1-y,a[i].y=n+1-x;
	}
	sort(a+1,a+1+p,cmp);
	for (int i=0;i<=m;i++) g[i]=1000000000;
	for (int i=1,q=1;i<=n;i++)
	{
		while (a[q].x<i) q++;
		while (a[q].x==i)
		{
			if (a[q].y>=m+1) s[m+1]++;else s[a[q].y]++;
			q++;
		}
		for (int j=m+1;j>=0;j--) s[j]+=s[j+1];
		for (int j=0;j<=m;j++)
		if (j==0)
		{
			for (int k=1;k<=m;k++) 
			g[j]=min(g[j],f[k-1]+k*(k+1)/2+2+s[k+1]*3);
			g[j]=min(g[j],f[0]+s[1]*3);
		}
		else g[j]=min(g[j-1],f[j-1]+s[j+1]*3);
		for (int j=0;j<=m;j++) f[j]=g[j],g[j]=1000000000;
		for (int j=0;j<=m+1;j++) s[j]=0;
	}
	printf("%d\n",f[0]);
	return 0;
}