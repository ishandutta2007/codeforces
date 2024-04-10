#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
ll n,m,k;
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
const int xx=1e4+5;
ll a[xx];
vector<pair<ll,ll> >v;
void check(ll x)
{
	ll now=0,fst=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i]%x==0)
		{
			if(!now)fst=i;
			if(now&&i-now!=x)puts("NO"),exit(0);
			now=i;
		}
	}
	if(!fst)return ;// 5 11// 
	if(fst>x)puts("NO"),exit(0);
//	cout<<now<<" ss "<<x<<"\n";
	if(now+x<=k)puts("NO"),exit(0);
	v.push_back(make_pair(x,(x+1-fst)%x));//mod first =second 
}
void exgcd(ll a,ll b,ll&x,ll&y)
{
	if(!b)return x=1,y=0,void();
	exgcd(b,a%b,x,y);
	ll X=y,Y=x-(a/b)*y;
	x=X,y=Y;
}
ll mul(ll a,ll b,ll mod){/*return (a*b%mod+mod)%mod;*/return (a*b-mod*(ll)((long double)a/mod*b)+mod)%mod;}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;i++)a[i]=read();
	ll lcm=a[1];
	for(int i=2;i<=k;i++)
	{
		ll d=gcd(lcm,a[i]);
		if(1.0l*lcm/d*a[i]>n)puts("NO"),exit(0);
		lcm/=d,lcm*=a[i];
//		cout<<lcm<<"\n";
	}
	for(ll x=1;x*x<=lcm;x++)
	{
		if(lcm%x==0)
		{
			check(x);
			if(lcm/x!=x)check(lcm/x);
		}
	}
//	for(auto it:v)cout<<it.second<<" mod "<<it.first<<"\n";
	if(lcm==1)puts("YES"),exit(0);
	ll nb=v[0].second,nc=v[0].first;
	for(int i=1;i<v.size();i++)
	{
		ll b=v[i].second,c=v[i].first,d=gcd(c,nc);
		if(abs(b-nb)%d)puts("NO"),exit(0);
		ll x,y;
		exgcd(nc,c,x,y);
//		cout<<d<<" "<<nc<<" "<<c<<" "<<x<<" "<<y<<" "<<b<<" "<<nb<<" "<<x<<" ss "<<(b-nb)/d<<"\n";
		x%=c/d,x=mul(x,(b-nb)/d,c/d),x+=c/d,x%=c/d;
		ll mod=nc/d*c;
		nb=(mul(nc,x,mod)+nb)%mod;
		nc=mod;
//		cout<<nb<<" "<<nc<<" "<<x<<" ss "<<c/d<<"\n";
	}
//	cout<<lcm<<" "<<nb<<" "<<nc<<"\n";
//	cout<<nb<<" "<<nc<<"ss \n";
	if(!nb)nb+=nc;
	if(nb<=m-k+1)puts("YES");
	else puts("NO");
	return 0;
}