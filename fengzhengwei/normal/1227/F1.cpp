#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e3+5;
int n,m,a[xx];
ll f[xx][xx+xx];
const int mod=998244353;
signed main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	f[0][n]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+n;j++)
		{
			if(a[i]==a[i%n+1])f[i][j]+=f[i-1][j]*m%mod,f[i][j]%=mod;
			else 
			{
				f[i][j]+=f[i-1][j]*(m-2)%mod;
				f[i][j]%=mod;
				f[i][j+1]+=f[i-1][j],f[i][j+1]%=mod;
				f[i][j-1]+=f[i-1][j],f[i][j-1]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=n+1;i<=n+n;i++)ans+=f[n][i],ans%=mod;
	cout<<ans<<"\n";
	return 0;
}