#include<bits/stdc++.h>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
const int N=500005;
ll n,k,a[N];
ll ans,sum[N],now;
int main(){
	n=read(),k=read()+1;
	For(i,1,n)
		a[i]=read();
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	For(i,1,n) sum[i]=sum[i-1]+a[i],now+=a[i]*(n-i);
	ans=now;
	Dow(i,1,n)
	{
		if((n-i)%k)
			now-=sum[i];
		ans=max(ans,now);
	}
	writeln(ans);
}