#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,dx,dy;
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)return x=1,y=0,void();
	exgcd(b,a%b,x,y);
	ll X=y,Y=x-(a/b)*y;
	x=X,y=Y;
}
ll gni(ll a)
{
	ll x,y;exgcd(a,n,x,y);
	x%=n,x+=n,x%=n;
	return x;
}
const int xx=1e6+5;
int t[xx],dxni;
signed main(){
	n=read(),m=read(),dx=read(),dy=read();
	dxni=gni(dx);
	for(int i=1;i<=m;i++)
	{
		ll a=read(),b=read();
		ll k=1ll*a*dxni%n;
		a-=dx*k,a%=n,a+=n,a%=n;
		b-=dy*k,b%=n,b+=n,b%=n;
		t[b]++;
	}
	int mx=0;
	for(int i=0;i<n;i++)mx=max(mx,t[i]);
//	cout<<mx<<'\n';
	for(int i=0;i<n;i++)if(t[i]==mx)cout<<0<<" "<<i<<"\n",exit(0);
	return 0;
}