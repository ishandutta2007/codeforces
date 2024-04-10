#include<iostream>
#include<cstdio>
//#include<ctime>
#define MX 800
using namespace std;
int n,k;double ans=0,f[MX+5],a[MX+5],b[MX+5],c[MX+5],d[MX+5],e[MX+5],g[MX+5];
int main()
{
	scanf("%d%d",&n,&k);
//	n=100000;k=1;
	f[1]=1;
	for(int i=1;i<=MX;++i) a[i]=(double)1/k,b[i]=a[i]/(i+1),c[i]=b[i]*i,d[i]=a[i]*i/2,e[i]=a[i]*(k-1)+c[i],g[i]=c[i]+d[i];
	//clock_t beg=clock();
	for(register int i=1;i<=n;++i)
		for(register int j=min(MX,i);j;--j)
		{
			if(f[j]<1e-100) continue;
			ans+=f[j]*g[j];
			f[j+1]+=f[j]*b[j];f[j]=f[j]*e[j];
		}
	printf("%.10lf\n",ans*k);
//	cerr<<(double)clock()-beg;
	return 0;
}