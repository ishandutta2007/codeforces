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
int n,a[105];
int f[105][10005];
int maxx[105];
int t[105];
ll jiec[105];
const int mod=1e9+7;
ll ksm(ll x,int y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans*=x,ans%=mod;
		x*=x;x%=mod;
		y>>=1;
	}
	return ans;
}
ll C(int x,int y)
{
	return jiec[x]*ksm(jiec[y],mod-2)%mod*ksm(jiec[x-y],mod-2)%mod;
}
int red(int x)
{
	return x>=mod?x-mod:x;
}
int main(){
	jiec[0]=1;
	for(int i=1;i<=100;i++)jiec[i]=jiec[i-1]*i%mod;
	n=read();
	int sum=0;
	for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++,sum+=a[i];
	
	f[0][0]=1;
	memset(maxx,-0x3f,sizeof(maxx));
	maxx[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=100;j>=0;j--)
		{
			for(int k=0;k<=maxx[j];k++)f[j+1][k+a[i]]=red(f[j+1][k+a[i]]+f[j][k]);
			maxx[j+1]=max(maxx[j+1],maxx[j]+a[i]);
		}
	}
	int ans=1;
	int o=0;
	for(int i=1;i<=100;i++)
	{
		if(t[i])
		{
			o++;
			int now=0;
			for(int j=1;j<=t[i];j++)
			{
				now+=i;
				if(f[j][now]==C(t[i],j))ans=max(ans,j);
			}
		}
	}
	if(o==2)ans=n;
	cout<<ans<<"\n";
	return 0;
}