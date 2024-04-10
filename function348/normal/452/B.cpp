#include<cstdio>
#include<cmath>
inline int min(int a,int b){ return a<b?a:b;}
inline int max(int a,int b){ return a>b?a:b;}
inline int sqr(int n){ return n*n;}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	double x1=max(n,m)+2*sqrt(n*n+m*m);
	double x2=sqrt(n*n+m*m)+2*sqrt(sqr(min(n,m)-1)+sqr(max(n,m)));
	if (n==0)	printf("%d %d\n%d %d\n%d %d\n%d %d\n",0,1,0,m,0,0,0,m-1);
	else
	if (m==0)	printf("%d %d\n%d %d\n%d %d\n%d %d\n",1,0,n,0,0,0,n-1,0);
	else
	if (x1>x2)	
	{
		if (n>m)printf("%d %d\n%d %d\n%d %d\n%d %d\n",0,0,n,m,0,m,n,0);
		else	printf("%d %d\n%d %d\n%d %d\n%d %d\n",0,0,n,m,n,0,0,m);
	}
	else
	{
		int x,y;
		if (n<m) x=1,y=0;else x=0,y=1;
		printf("%d %d\n%d %d\n%d %d\n",x,y,n,m,0,0);
		if (n<m) x=n-1,y=m;else x=n,y=m-1;
		printf("%d %d\n",x,y);
	}
	return 0;
}