#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 1000000
#define MX 50
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
double ans=0;
int n,a[MN+5],ne[MN+5],la[MN+5],rk[MN+5];
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),ne[i]=i+1,la[i]=i-1,rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		double s=1,tl=0,tr=0;int l=rk[i],r=rk[i];
		for(int j=1;j<=MX;++j)
		{
			if(l) tl+=(l-la[l])*s,l=la[l];
			if(r<=n) tr+=(ne[r]-r)*s,r=ne[r];
			s*=0.5;
		}
		ans+=tl*tr*a[rk[i]];
		ne[la[rk[i]]]=ne[rk[i]];
		la[ne[rk[i]]]=la[rk[i]];
	}
	printf("%.10lf\n",ans/n/n/2);
	return 0;
}