#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define inf 2e13
#define pa pair<int,int>
#define sec second
#define mk make_pair
#define fir first
#define int ll

using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
int n,m;
const int N=2e6+6;
ll fac[N],rev[N],po[N],mo=998244353;
inline ll ksm(ll x,ll y){ll sum=1;for(;y;y/=2,x=x*x%mo)	if(y&1)	sum=sum*x%mo;return sum;}
inline ll C(ll x,ll y){return fac[x]*rev[y]%mo*rev[x-y]%mo;}
signed main()
{
    n=read();    
	if(n<m){puts("0");return 0;}
    fac[0]=1;po[0]=1;For(i,1,n)	fac[i]=fac[i-1]*i%mo,po[i]=po[i-1]*(3)%mo;
    rev[n+m]=ksm(fac[n],mo-2);
    Dow(i,0,n-1)	rev[i]=rev[i+1]*(i+1)%mo;
	ll f=-1,ans=0;
    For(i,0,n-1)	
    {
    	ans+=C(n,i)*f*(ksm((1-po[i]),n)-ksm(-po[i],n)+mo)%mo;
    	ans=(ans%mo+mo)%mo;
    	f=-f;
	}
	ans=ans*3%mo;
	f=1;
	For(i,1,n)
	{
		ans+=2*f*C(n,i)*ksm(3,(n*(n-i)+i))%mo;
		f=-f;
		ans=(ans%mo+mo)%mo;
	}
	writeln(ans);
}