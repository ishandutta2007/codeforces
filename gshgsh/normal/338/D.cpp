#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll __int128
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 10001
ll N,M,K,a[MAXN];
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void EXGCD(ll a,ll b,ll&x,ll&y){b?EXGCD(b,a%b,y,x),y-=a/b*x:(x=1,y=0);}
void mrg(ll&a,ll&p,ll a1,ll p1)
{
	ll d=__gcd(p,p1),newp=p/d*p1,c=(a1-a+newp)%newp;if(c%d){cerr<<"error\n";exit(0);}
	ll v=p/d,v1=p1/d;c/=d;ll x,y;EXGCD(v,v1,x,y);x=(x%v1+v1)%v1;x=x*c%v1;a+=x*p;p=newp;
}
int main()
{
	N=get(),M=get(),K=get();For(i,1,K)a[i]=get();
	ll lcm=a[1];For(i,2,K){lcm=lcm/__gcd(lcm,a[i])*a[i];if(lcm>N){cout<<"NO\n";return 0;}}ll x=lcm;
	ll y=0,p=1;For(i,1,K)mrg(y,p,(1-i%a[i]+a[i])%a[i],a[i]);if(!y)y=x;if(y>M-K+1){cout<<"NO\n";return 0;}
	For(i,1,K)if(__gcd(x,y+i-1)!=a[i]){cout<<"NO\n";return 0;}cout<<"YES\n";return 0;
}