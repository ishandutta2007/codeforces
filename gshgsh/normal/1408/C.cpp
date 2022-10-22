#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) max(x,-(x))
#define eps 1e-8
#define MAXN 100001
int T,N,L,a[MAXN];
int get(){char c=getchar();int x=0;while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),L=get();For(i,1,N)a[i]=get();
		double l=0,r=L,ans=0;int i=1,j=N,va=1,vb=1;while(i<=j){double t=min(1.0*(a[i]-l)/va,1.0*(r-a[j])/vb);ans+=t;l+=va*t,r-=vb*t;if(abs(l-a[i])<eps)i++,va++;if(abs(r-a[j])<eps)j--,vb++;}
		printf("%.8lf\n",ans+(r-l)/(va+vb));
	}
	return 0;
}