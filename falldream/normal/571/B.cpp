#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 300000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,m,a[MN+5],len;
long long *f[MN+5];
inline void R(long long&x,long long y){y<x?x=y:0;}
int main()
{
	n=read();k=read();len=n/k;m=n%k;
//	cout<<len<<" "<<m<<" "<<k<<endl;
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=0;i<=k;++i)
	{
		f[i]=new long long[m+5];
		for(int j=0;j<=m;++j) f[i][j]=(long long)1e18;	
	}
	f[0][0]=0;
	for(int i=0;i<k;++i) for(int j=0;j<=min(i,m);++j) 
	{
		int now=i*len+j+1;
		R(f[i+1][j],f[i][j]+a[now+len-1]-a[now]);
		if(j<m) R(f[i+1][j+1],f[i][j]+a[now+len]-a[now]);
	//	cout<<i<<" "<<j<<" "<<now+len<<" "<<now<<endl;
	}
	printf("%lld\n",f[k][m]); 
	return 0;
}