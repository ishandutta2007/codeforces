#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[4105];bitset<16400> b[4101];
int n,m,fa[32805],ans=0,nx[32805],vis[32805],bel[32805];
inline int getfa(int x){return fa[x]?fa[x]=getfa(fa[x]):x;}
inline void Merge(int x,int y){if(getfa(x)!=getfa(y)) fa[getfa(x)]=getfa(y),--ans;}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",st+1);
		for(int j=1;j<=m/4;++j)
		{
			int x;
			if(st[j]>='A'&&st[j]<='F') x=st[j]-'A'+10;
			else x=st[j]-'0';
			for(int k=4;k;--k,x>>=1) b[i][j*4-4+k]=x&1; 	
		}
	}
	for(int i=1,s=m;i<=n;++i,s^=m)
	{
		for(int j=1;j<=m;++j) 
		{
			int x=getfa(j+(s^m));
			if(vis[x]!=i) vis[x]=i,bel[x]=j+(s^m),nx[j+(s^m)]=0;
			else nx[j+(s^m)]=bel[x];
		}
		for(int j=1;j<=m;++j) fa[s+j]=0,fa[(s^m)+j]=nx[(s^m)+j]; 
		for(int j=1;j<=m;++j)	
			if(b[i][j])
			{
				++ans;
				if(j>1&&b[i][j-1]) Merge(s+j,s+j-1);
				if(i>1&&b[i-1][j]) Merge(s+j,(s^m)+j);
			}	
	}
	printf("%d\n",ans);
	return 0;
}