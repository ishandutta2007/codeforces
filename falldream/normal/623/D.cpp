#include<iostream>
#include<cstdio>
#define MN 100
#define MX 1000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[MN+5];
double p[MN+5],w[MN+5],ans=0;
int main()
{
	ans=n=read();
	for(int i=1;i<=n;++i) a[i]=read(),p[i]=a[i]/100.0;
	for(int i=n+1;i<=MX;++i)
	{
		double mx=0,P=1;int from=0;
		for(int j=1;j<=n;++j) P*=p[j];
		for(int j=1;j<=n;++j)
		{
			double add=(1-p[j])*a[j]/100*(P/p[j]);
			if(add>mx) mx=add,from=j;	
		}
		ans+=1-P;p[from]=p[from]+(1-p[from])*a[from]/100;
	}
	printf("%.10lf\n",ans);
	return 0;
}