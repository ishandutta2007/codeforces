#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=1e5+5;
char s[xx];
int n;
int C(char c)
{
	if('a'<=c&&c<='z')return c-'a'+1;
	if('A'<=c&&c<='Z')return c-'A'+27;
}
int t[55];
const int mod=1e9+7;
ll jiec[xx],ni[xx];
ll ksm(ll x,int y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans*=x,ans%=mod;
		x*=x,x%=mod;
		y>>=1;
	}
	return ans;
}
ll c(int n,int m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
ll f[xx],p;
void tui(int x){for(int j=x;j<=p/2;j++)f[j]-=f[j-x],f[j]+=mod,f[j]%=mod;}
void jia(int x){for(int j=p/2;j>=x;j--)f[j]+=f[j-x],f[j]%=mod;}
ll ans[55][55];
signed main(){
	jiec[0]=1;
	for(int i=1;i<=1e5;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[100000]=ksm(jiec[100000],mod-2);
	for(int i=1e5-1;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	scanf("%s",s+1);
	p=strlen(s+1);
	for(int i=1;i<=p;i++)t[C(s[i])]++;
	f[0]=1;
	for(int i=1;i<=52;i++)
	{
		if(!t[i])continue;
		jia(t[i]);
	}
	ll ss=jiec[p/2]*jiec[p/2]%mod;
	for(int i=1;i<=52;i++)ss*=ni[t[i]],ss%=mod;
//	cout<<ss<<'\n';
	for(int i=1;i<=52;i++)
	{
		if(!t[i])continue;
		tui(t[i]);
		for(int j=1;j<=52;j++)
		{
			if(!t[j])continue;
			if(i==j)continue;
			if(t[i]+t[j]>p/2){ans[i][j]=0;continue;}
			tui(t[j]);
			ans[i][j]=f[p/2-t[i]-t[j]]*ss*2%mod;
			jia(t[j]);
		}
		jia(t[i]);
	}
	n=read();
	while(n--)
	{
		int a,b;
		a=read(),b=read();
		if(s[a]==s[b])
		{
			if(t[C(s[a])]>p/2)puts("0");
			else cout<<f[p/2]*ss%mod<<'\n';
		}
		else 
		{
			if(t[C(s[a])]+t[C(s[b])]>p/2)puts("0");
			else 
				cout<<ans[C(s[a])][C(s[b])]<<'\n';
		}
	}
	return 0;
}