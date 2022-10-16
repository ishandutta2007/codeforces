#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int getfi(int x)
{
	int now=x;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			now=(now-now/i);
			while(x%i==0)x/=i;
		}
	}
	if(x!=1)
	{
		int i=x;
		if(x%i==0)
		{
			now=(now-now/i);
			while(x%i==0)x/=i;
		}
	}
	return now;
}
const int xx=1e5+5;
vector<int>v;
int n,m,a[xx],vs;
ll ksm(ll a,ll b,ll mod)
{
	ll ans=1;
	ll vs1=0;
	while(b)
	{
		if(b&1)ans*=a,vs|=(ans>=mod),vs|=vs1,ans%=mod;
		a*=a,vs1|=(a>=mod),a%=mod;b>>=1;
	}
	return ans;
}
signed main(){
	n=read(),m=read();
	v.push_back(m);
	while(*--v.end()!=1)v.push_back(getfi(*--v.end()));
	for(int i=1;i<=n;i++)a[i]=read();
	int q=read();
	while(q--)
	{
		int l=read(),r=read();
		r=min(r,l+(int)v.size()-1);
		ll ans=1;
		for(int i=r;i>=l;i--)
		{
			vs=0;
			ans=ksm(a[i],ans,v[i-l]);
			if(vs)ans+=v[i-l];
		}
		cout<<ans%v[0]<<"\n";
	}
	return 0;
}