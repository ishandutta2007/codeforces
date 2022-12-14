#include<bits/stdc++.h>
#define MN 500
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[MN+5][MN+5],n,K,ans;
int main()
{
	f[0][0]=1;n=read();K=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();if(x>K) continue;
		for(int j=K-x;~j;--j) for(int k=j;~k;--k) 
			if(f[j][k]) f[j+x][k]=f[j+x][k+x]=1;
	}
	for(int i=0;i<=K;++i) ans+=f[K][i];
	printf("%d\n",ans);
	for(int i=0;i<=K;++i) if(f[K][i]) printf("%d ",i);
	return 0;
}