#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;double p[MN+5],ans=0;
double pow(double x,int t)
{
	double sum=1;
	for(;t;t>>=1,x=x*x) if(t&1) sum=sum*x;
	return sum;
}
int main()
{
	m=read();n=read();
	for(int i=1;i<=m;++i) p[i]=pow((double)i/m,n),ans+=(p[i]-p[i-1])*i;
	printf("%.10lf\n",ans);
	return 0;
}