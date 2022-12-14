#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<bitset>
#define ll long long
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
bitset<505> s[2][502][62];
ll f[2][502][62];
int n,m;
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
		int u=read(),v=read(),w=read();
		s[w][u][0][v]=1;
	}
    for(int k=0;k<60;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(s[0][i][k][j])s[0][i][k+1]|=s[1][j][k];
				if(s[1][i][k][j])s[1][i][k+1]|=s[0][j][k];
			}	
	memset(f,128,sizeof(f));f[0][1][61]=0;
    for(int k=60;k>=0;k--)
    {
		for(int i=1;i<=n;i++)
		{
			f[0][i][k]=f[0][i][k+1];
			f[1][i][k]=f[1][i][k+1];	
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{	
				if(s[1][i][k][j]) f[0][j][k]=max(f[0][j][k],f[1][i][k+1]+(1LL<<k));
				if(s[0][i][k][j]) f[1][j][k]=max(f[1][j][k],f[0][i][k+1]+(1LL<<k));
			}
		}
	}
	ll mx=0;
	for(int i=1;i<=n;i++)mx=max(mx,max(f[1][i][0],f[0][i][0]));
	if(mx>=1000000000000000000LL)puts("-1");
	else printf("%I64d\n",mx);
    return 0;
}