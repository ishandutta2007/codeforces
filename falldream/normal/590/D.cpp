#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 150
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,s,f[MN+5][MN*MN+5],a[MN+5];
inline void R(int&x,int y){y<x?x=y:0;}
int main()
{
	n=read();k=read();s=min(read(),k*(n-k)+5);
	memset(f,127,sizeof(f));f[0][s]=0;int ans=2e9;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=min(i,k)-1;~j;--j)
			for(int l=0;l<=s;++l) 
				if(f[j][l]<2e9&&i-j-1<=l) R(f[j+1][l-(i-j-1)],f[j][l]+a[i]);
	for(int l=0;l<=s;++l) R(ans,f[k][l]);
	printf("%d\n",ans);
	return 0;
}