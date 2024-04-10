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

int n,m,a[500010],b[500010];
int main()
{
	int T=read();
	while (T--)
	{
		n=read(),m=read();
		For(i,1,n) a[i]=read();
		sort(a+1,a+1+n);
		For(i,1,m) b[i]=read();
		int pos=n;
		ll ans=0;
		For(i,1,m) if (i<=a[pos]) ans+=b[i],--pos;
		Dow(i,1,pos) ans+=b[a[i]];
		writeln(ans);
	}
}