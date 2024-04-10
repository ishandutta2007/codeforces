#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
 
 
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
/*------------------------------------------------------------------------------------------------------*/

#define int ll 
const int N=1e6+5,mo=1e9+7;
int n,l[N],r[N],v[N],pos[N],S;
inline ll ksm(ll x,ll y){ll sum=1;for(;y;y/=2,x=x*x%mo)	if(y&1)	sum=sum*x%mo;return sum;}
signed main()
{
	n=read();
	For(i,1,n)	l[i]=read();
	For(i,1,n)	r[i]=read();
	For(i,1,n)	v[i]=ksm(r[i]-l[i]+1,mo-2);
	For(i,2,n)
	{
		ll len=max(0LL,min(r[i],r[i-1])-max(l[i],l[i-1])+1);
		S=S+(pos[i]=len*v[i]%mo*v[i-1]%mo);S%=mo;
	}
	ll ans=n*n%mo-2*S%mo*n%mo;ans=(ans%mo+mo)%mo;
	For(i,2,n)
	{
		ans=(ans+pos[i])%mo;
		ll tmp=S-pos[i];
		if(i!=2)	tmp-=pos[i-1];if(i!=n)	tmp-=pos[i+1];
		tmp=(tmp%mo+mo)%mo;
		ans=(ans+tmp*pos[i]%mo)%mo;
		//cout<<ans<<endl;
		if(i!=2)	ans=(ans+v[i]*v[i-1]%mo*v[i-2]%mo*max(0LL,min(r[i],min(r[i-2],r[i-1]))-max(l[i],max(l[i-1],l[i-2]))+1)%mo)%mo;
		if(i!=n)	ans=(ans+v[i]*v[i+1]%mo*v[i-1]%mo*max(0LL,min(r[i],min(r[i+1],r[i-1]))-max(l[i],max(l[i-1],l[i+1]))+1)%mo)%mo;
	//	cout<<ans<<endl;
	}
	writeln(ans);
}