#include<cstdio>
#include<string>
#include<iostream>
#include<map>
#define For(i,j,k) for(register ll i=j;i<=k;++i)
#define Dow(i,j,k) for(register ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
ll n,v[5],a[200001],f[200001][4],ans=-4e18,g[200001][4];
int main()
{
	n=read();For(i,1,3)	v[i]=read();
	For(i,1,n)	a[i]=read();
	For(i,1,3)	g[0][i]=-4e18;
	For(i,0,n)	For(j,1,3)	f[i][j]=-4e18;
	For(i,1,n)
	{
		For(j,1,3)
		{
			f[i][j]=max(f[i-1][j],g[i][j-1]+v[j]*a[i]);	
			g[i][j]=max(g[i-1][j],f[i][j]);
			if(j==3)	ans=max(ans,f[i][j]);
		}
	}
	cout<<ans<<endl;
}