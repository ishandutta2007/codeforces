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
const int xx=2e5+5;
ll n,m,a[xx],s,st[xx];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)return x=1,y=0,a;
	ll d=exgcd(b,a%b,x,y);
	ll X=y,Y=x-(a/b)*y;
	x=X,y=Y;
	return d;
}
ll id[xx];
map<ll,vector<int> >mp;
map<ll,int>ms;
signed main(){
	m=read(),n=read();
	for(int i=1;i<=n;i++)a[i]=read(),s+=a[i];
	for(int i=2;i<=n;i++)st[i]=st[i-1]+a[i],st[i]%=m;
	ll x,y;
	ll d=exgcd(s,m,x,y);
	for(int i=1;i<=n;i++)
	{
		d=exgcd(s,m,x,y);
		x*=(st[i]-st[i]%d)/d;
		x%=(m/d),x+=(m/d),x%=(m/d);
		id[i]=x;
		mp[st[i]%d].push_back(id[i]);
	}
	for(map<ll,vector<int> >::iterator it=mp.begin();it!=mp.end();it++)sort(it->second.begin(),it->second.end());
	for(int i=1;i<=n;i++)
	{
		if(ms[st[i]]){puts("0");continue;}
		ms[st[i]]=1;
		vector<int>::iterator it=upper_bound(mp[st[i]%d].begin(),mp[st[i]%d].end(),id[i]);
		ll to=it!=mp[st[i]%d].end()?*it:*mp[st[i]%d].begin();
		to-=id[i];to%=(m/d),to+=(m/d),to%=(m/d);
		if(!to)to+=m/d;
		cout<<to<<' ';
	}
	puts("");
	return 0;
}