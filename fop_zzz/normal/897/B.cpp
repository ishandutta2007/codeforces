#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#define For(i,j,k)	for(register int i=j;i<=k;++i)
#define Dow(i,j,k)	for(register int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;	c=getchar();}
    while(c>='0'&&c<='9')	t=t*10+c-'0',c=getchar();
    return t*f;
}
inline void write(ll x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
ll n,p,s[20001],sum,ans,mo;
int main()
{
	n=read();mo=read();
	For(i,1,n)
	{
		ll top=0,tmp=i;
		while(tmp)	s[++top]=tmp%10,tmp/=10;
		For(i,1,top/2)	swap(s[i],s[top-i+1]);
		ll ttop=top;
		For(j,ttop+1,ttop*2)
			s[++top]=s[ttop-(j-ttop)+1];
		ll sum=0;
		Dow(i,1,top) 	
			sum*=10,sum+=s[i],sum%=mo;
		ans=(ans+sum)%mo;
	}
	cout<<ans<<endl;
 }