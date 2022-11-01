#include<bits/stdc++.h>
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define ll long long
#define pa pair<int,int>
#define mk make_pair
#define fir first
#define sec second
#define IT  set<pair<int,int> > :: iterator
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') f=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-'0',c=getchar();
    return t*f;
}
  
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
ll n,h;
inline ll Get(ll x)
{
	ll tmp=h*(h-1)/2;x-=h-1;
	ll len=x/2;
	if(x&1)	tmp+=h+len;
	tmp+=(h+h+len-1)*len;
	return tmp;
}
int main()
{
	n=read();
	h=read();
	if(h>2e9||n<=h*(h+1)/2)	
	{
		ll l=1,r=2e9,ans=0;
		while(l<=r)	
		{
			ll mid=l+r>>1;
			if((mid*(mid+1))/2>=n)	ans=mid,r=mid-1;else	l=mid+1;
		}
		writeln(ans);
		return 0;
	}
	ll l=h,r=4e9+10,ans=0;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(Get(mid)>=n)	ans=mid,r=mid-1;else	l=mid+1;
	}
	writeln(ans);
}