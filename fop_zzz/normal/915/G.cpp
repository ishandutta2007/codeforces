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

const int N=2e6+6;
ll mo=1e9+7,n,k,po[N],ans[N],pri[N],mu[N],tot;
bool bj[N];
inline void Pre()
{
	mu[1]=1;
	For(i,2,k)
	{
		if(!bj[i]){pri[++tot]=i;mu[i]=-1;}
		For(j,1,tot)
		{
			if(i*pri[j]>k)	break;
			bj[i*pri[j]]=1;mu[i*pri[j]]=-mu[i];
			if(i%pri[j]==0){mu[i*pri[j]]=0;break;}
		}
	}
}
inline ll ksm(ll x,ll y){ll sum=1;for(;y;y/=2,x=x*x%mo)	if(y&1)	sum=sum*x%mo;return sum;}
int main()
{
	n=read();k=read();
	For(i,1,k)	po[i]=ksm(i,n);
	Pre();
	For(i,1,k)
	{
		for(int j=i;j<=k;j+=i)	
			ans[j]+=mu[i]*(po[j/i]-po[j/i-1]),ans[j]=(ans[j]%mo+mo)%mo;// 
	}
	For(i,1,k)	ans[i]+=ans[i-1],ans[i]%=mo;
	ll tans=0;
	For(i,1,k)	tans=(tans+(ans[i]^i))%mo;
	writeln(tans);
}