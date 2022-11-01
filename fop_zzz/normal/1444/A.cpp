#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
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


ll ans;
inline void Check(ll a,ll b,ll div)
{
	if(div==1)	return;
	ll tim=0,tim1=0;
	ll ta=a,tb=b;
	while(tb%div==0)	tb/=div,tim++;
	while(ta%div==0)	ta/=div,tim1++;
	int del=tim1-tim+1;
	For(i,1,del)	a/=div;
	ans=max(ans,a);
}
int main()
{
	int T=read();
	while(T--)
	{
		ll a=read(),b=read();
		if(a%b!=0)	writeln(a);
		else
		{
			ll tmp=sqrt(b);
			ans=0;
			For(i,1,tmp)	if(b%i==0)
			{
				Check(a,b,i);
				Check(a,b,b/i);
			}
			writeln(ans);
		}
	}
}