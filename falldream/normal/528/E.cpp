#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#define MN 3000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;double ans=0;
struct Line{double a,b,c;double slop;}s[MN+5];
bool cmp(const Line&x,const Line&y){return x.slop<y.slop;}
void Inter(int i,int j,double&x,double&y)
{
//	ax+by+c=0 aAx+bAy+cA=0
//	Ax+By+C=0 aAx+aBy+aC=0
//	(bA-aB)y=-cA+aC
//	ax+by+c=0 aBx+bBy+cB=0
//	Ax+By+C=0 bAx+bBy+bC=0
//	(aB-bA)x=bC-cB
	y=(s[i].a*s[j].c-s[i].c*s[j].a)/(s[i].b*s[j].a-s[i].a*s[j].b);
	x=(s[i].b*s[j].c-s[i].c*s[j].b)/(s[i].a*s[j].b-s[j].a*s[i].b);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) 
	{
		s[i].a=read(),s[i].b=read(),s[i].c=read();
		if(s[i].a<0) s[i].a*=-1,s[i].b*=-1,s[i].c*=-1;
		s[i].slop=atan2(s[i].b,-s[i].a);
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		double X=0,Y=0;
		for(int j=i%n+1;j!=i;j=j%n+1)
		{
			double x,y;Inter(i,j,x,y);
			ans+=x*Y-X*y;X+=x;Y+=y;
		}
	}
	printf("%.10lf\n",ans*3/n/(n-1)/(n-2));
	return 0;
}