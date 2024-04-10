#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 500
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,b,mod,a[MN+5],f[MN+5][MN+5];
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int main()
{
	n=read();m=read();b=read();mod=read();
	for(int i=1;i<=n;++i) a[i]=read();
	f[0][0]=1%mod;
	for(int i=1;i<=n;++i) for(int j=0;j<m;++j) for(int k=0;k<=b-a[i];++k)
		R(f[j+1][k+a[i]],f[j][k]);
	int ans=0;
	for(int i=0;i<=b;++i) R(ans,f[m][i]);
	printf("%d\n",ans);
	return 0;
}