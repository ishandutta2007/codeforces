#include<bits/stdc++.h>
#define MN 3000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5];
int f[MN+5][MN+5],n,D,inv[MN+5],p[MN+5],ans;
void dfs(int x)
{
	for(int i=1;i<=min(n,D);++i) f[x][i]=1;
	for(int i=0;i<v[x].size();++i)
	{
		dfs(v[x][i]);int s=0;
		for(int j=1;j<=min(n,D);++j) 
			s=(s+f[v[x][i]][j])%mod,f[x][j]=1LL*f[x][j]*s%mod;
	}
}
inline int C(int n,int m){return 1LL*p[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	n=read();D=read();inv[0]=inv[1]=p[0]=p[1]=1;
	for(int i=2;i<=n;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;++i) v[read()].push_back(i),inv[i]=1LL*inv[i-1]*inv[i]%mod;
	dfs(1);int res=1;
	for(int i=1;i<=min(n,D);++i)
	{
		res=1LL*res*(D-i+1)%mod;
		for(int j=1;j<i;++j) f[1][i]=(f[1][i]-1LL*C(i-1,j-1)*f[1][j]%mod+mod)%mod;
		ans=(ans+1LL*res*f[1][i]%mod*inv[i])%mod;
	}
	cout<<ans;
	return 0;
}