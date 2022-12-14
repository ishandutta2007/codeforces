#include<iostream>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5];
double ans=1e18;
inline double Abs(double x){return x<0?-x:x;}
double Calc(double x)
{
	double res=0,mn=0,mx=0,pre=0;
	for(int i=1;i<=n;++i)
	{
		pre+=a[i]-x;
		res=max(res,max(Abs(pre-mn),Abs(pre-mx)));
		mn=min(mn,pre);mx=max(mx,pre);
	}
	return ans=min(ans,res),res;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	double m1,m2,l=-10000,r=10000,mid;
	for(int i=1;i<=100;++i)
	{
		m1=l+(r-l)/3;
		m2=m1+(r-l)/3;
		if(Calc(m1)>Calc(m2)) l=m1;
		else r=m2;
	}
	printf("%.10lf\n",ans);
	return 0;
}